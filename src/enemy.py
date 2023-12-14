import numpy as np

from main import *


class EnemyType(Enum):
    Pneumococos = (
        "Pneumococos",
        0.9,
        0.7,
        None
    )
    Staphylococcus = (
        "Staphylococcus",
        0.9,
        0.7,
        None
    )
    Streptococcus = (
        "Streptococcus",
        1,
        0.9,
        None
    )


EnemySound = pg.mixer.Sound(f'assets/sounds/enemy.mp3')
EnemySound.set_volume(VOLUME / 100)


class Enemy(MovingSprite):
    def __init__(self, game, enemy: EnemyType, x, y, route=None):
        name, scale, shift, action = enemy.value
        super().__init__(game, name, x, y, scale, shift, action, route=route)

        self.enemy = enemy
        self.health = 100
        self.damage = 10

        self.angle = 0
        self.speed = 150

        self.time = 0
        self.attack_cooldown = 1

    def seeing_player(self) -> bool:
        player_x, player_y = self.game.player.x, self.game.player.y
        sprite_x, sprite_y = self.x, self.y
        dx, dy = player_x - sprite_x, player_y - sprite_y

        player_dist = (np.sqrt(dx ** 2 + dy ** 2) // Tile_size) + 1
        angle_ray = math.atan2(dy, dx)
        angle_ray = angle_to_fist(angle_ray)

        world_map = self.game.map.world_wall
        is_render = self.game.map.tiles_to_render

        return numba_seeing_player(sprite_x, sprite_y, player_dist, world_map, is_render, angle_ray)

    def kill(self):
        self.game.sprite_handler.sprites.remove(self)

        if self.enemy is EnemyType.Staphylococcus:
            if self.scale > 0.2:
                for _ in range(2):
                    self.game.sprite_handler.add(
                        enemy := Enemy(
                            self.game,
                            EnemyType.Staphylococcus,
                            self.x + random.uniform(-15, 15),
                            self.y + random.uniform(-15, 15),
                            route=self.walking_route
                        )
                    )
                    enemy.scale = self.scale / 2
                    enemy.health = self.health / 2
                    enemy.damage = self.damage / 2
                    enemy.speed = self.speed * 2
                    enemy.height_shift = self.height_shift/2

    def update(self):
        self.attack_cooldown -= self.game.delta_time

        if self.seeing_player():
            self.walking_route = False
            self.game.scheduler.add_dict((self, 'rout'), 10, setattr, self, 'walking_route', True)
            if self.go_to(self.game.player.x, self.game.player.y, 92):
                if self.attack_cooldown <= 0:
                    self.game.player.health -= self.damage

                    EnemySound.play()

                    self.game.hud.set_face(1)
                    self.game.scheduler.add_dict('face', 8, self.game.hud.set_face, 0)

                    self.attack_cooldown = 2

        super().update()


@njit(fastmath=FastMath)
def numba_seeing_player(sprite_x, sprite_y, player_dist, world_map, is_render, angle_to_player):
    a_tan = -1 / (np.tan(angle_to_player) + 0.00001)
    rendist = 1
    if angle_to_player > np.pi:  # looking up
        ray_y = (sprite_y // Tile_size) * Tile_size - 0.0001
        ray_x = sprite_x + ((sprite_y - ray_y) * a_tan)
        offset_y = -Tile_size
        offset_x = -offset_y * a_tan
    else:  # looking down
        ray_y = (sprite_y // Tile_size) * Tile_size + Tile_size
        ray_x = sprite_x + ((sprite_y - ray_y) * a_tan)
        offset_y = Tile_size
        offset_x = -offset_y * a_tan

    while rendist < player_dist:
        y = int(ray_y // Tile_size)
        if 0 <= y < len(world_map):
            x = int(ray_x // Tile_size)
            if 0 <= x < len(world_map[y]):
                if world_map[y][x] in is_render:
                    return False
        # else:
        ray_x += offset_x
        ray_y += offset_y
        rendist += 1

    # Calculo vertical -=-=-=-=-=-=-=-=-=-=
    a_tan = -np.tan(angle_to_player)
    rendist = 1
    if angle_to_player < np.pi / 2 or angle_to_player > np.pi * 3 / 2:  # looking right
        ray_x = (sprite_x // Tile_size) * Tile_size + Tile_size
        ray_y = sprite_y + ((sprite_x - ray_x) * a_tan)
        offset_x = Tile_size
        offset_y = -offset_x * a_tan
    else:  # looking left
        ray_x = (sprite_x // Tile_size) * Tile_size - 0.0001
        ray_y = sprite_y + ((sprite_x - ray_x) * a_tan)
        offset_x = -Tile_size
        offset_y = -offset_x * a_tan

    while rendist < player_dist:
        y = int(ray_y // Tile_size)
        if 0 <= y < len(world_map):
            x = int(ray_x // Tile_size)
            if 0 <= x < len(world_map[y]):
                if world_map[y][x] in is_render:
                    return False
        # else:
        ray_x += offset_x
        ray_y += offset_y
        rendist += 1

    return True
