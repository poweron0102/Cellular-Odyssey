import random

from main import *

Animations = {
    'blood': [
        pg.transform.scale_by(pg.image.load(f'assets/sprites/animations/bloodfx{i}.png').convert_alpha(), 3)
        for i in range(1, 6)
    ],
}


class Sprite:
    def __init__(self, game, name, x, y, scale=0.5, shift=0.05, action=None):
        self.game: InGame = game
        self.player = game.player

        self.x = x
        self.y = y

        self.image = pg.image.load(f'assets/sprites/{name}.png').convert_alpha()

        self.width = self.image.get_width()
        self.height = self.image.get_height()
        # self.image_ratio = self.width / self.height

        self.dist = 1
        self.delta_ang = 1
        self.screen_x = 1

        self.scale = scale
        self.height_shift = shift
        self.action = action

        self.play_animation = False
        self.time = 0
        self.animation: list[pg.Surface] | None = None
        self.animation_time: float = 0
        self.animation_offset: tuple[int, int] = 0, 0

    def update(self):
        if self.play_animation:
            image: pg.Surface = self.image.copy()
            self.time += self.game.delta_time
            if self.time >= self.animation_time:
                self.play_animation = False
                self.time = 0
            else:
                frame: pg.Surface = self.animation[int(self.time / self.animation_time * len(self.animation))]
                image.blit(
                    frame,
                    (
                        self.animation_offset[0] - frame.get_width() / 2,
                        self.animation_offset[1] - frame.get_height() / 2
                    )
                )
        else:
            image = self.image

        dx = self.x - self.player.x
        dy = self.y - self.player.y

        sprite_ang = math.atan2(dy, dx)
        self.delta_ang = sprite_ang - self.player.ang
        if (dx > 0 and self.player.ang > math.pi) or (dx < 0 and dy < 0):
            self.delta_ang += math.tau  # tau == 2PI

        delta_rays = self.delta_ang / math.radians(FOV / (RES[0] / SCALE))
        self.screen_x = ((RES[0] / SCALE) / 2 + delta_rays) * SCALE

        self.dist = math.hypot(dx, dy)
        view_dist = self.dist * math.cos(self.delta_ang)
        # dist = self.dist * math.cos(delta_ang)
        if -self.width / 2 < self.screen_x < RES[0] + (self.width / 2) and view_dist > 10:
            item = view_dist, self.scale, image, self.height, self.screen_x, self.height_shift
            self.game.drawer.to_draw.append((3, item))
            self.game.sprite_handler.sprites_seeing.append(self)

        if self.action and self.game.player.interact and self.dist < Tile_size:
            self.action(self)
            self.action = None

    def PlayAnimation(self, animation_name: str, time: float, offset=None):
        self.play_animation = True
        self.animation = Animations[animation_name]
        self.animation_time = time
        if offset is tuple:
            self.animation_offset = offset
        elif type(offset) is float:
            self.animation_offset = (
                random.randint(int(self.width * offset), int(self.width * (1 - offset))),
                random.randint(int(self.height * offset), int(self.height * (1 - offset)))
            )
        else:
            self.animation_offset = (0, 0)


class SpriteHandler:
    def __init__(self, game):
        self.game: InGame = game
        self.sprites: list[Sprite] = []
        self.sprites_seeing: list[Sprite] = []
        self.sprites_dict: dict[Any, Sprite] = {}

    def update(self):
        self.sprites_seeing.clear()
        for sprite in self.sprites:
            sprite.update()
        for sprite in self.sprites_dict.values():
            sprite.update()

    def add(self, sprite: Sprite):
        self.sprites.append(sprite)

    def add_dict(self, sprite: Sprite, key):
        self.sprites_dict[key] = sprite

    def remove_dict(self, key):
        self.sprites_dict.pop(key)


class MovingSprite(Sprite):
    def __init__(self, game, name, x, y, scale=1, shift=1, speed=50, route=None, action=None):
        super().__init__(game, name, x, y, scale, shift, action)
        self.angle = 0
        self.speed = speed

        self.time = 0
        self.route = route if route else []
        self._route = []
        self.walking_route = True

    def go_to(self, x, y, min_dist=5):
        dx, dy = x - self.x, y - self.y
        self.angle = math.atan2(dx, dy)
        if min_dist:
            if dx ** 2 + dy ** 2 <= min_dist ** 2:
                return True
        self.x += math.sin(self.angle) * (self.speed + random.randint(-10, 10)) * self.game.delta_time
        self.y += math.cos(self.angle) * (self.speed + random.randint(-10, 10)) * self.game.delta_time
        return False

    def update(self):
        if self.walking_route:
            if len(self.route) > 0 and len(self._route) == 0:
                self._route = self.route.copy()
                self.x, self.y = self._route[0][0], self._route[0][1]

            if len(self._route) > 0:
                if self.go_to(self._route[0][0], self._route[0][1]):
                    self._route.pop(0)

        super().update()
