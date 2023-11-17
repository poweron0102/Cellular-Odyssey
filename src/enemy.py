import numpy as np

from main import *


class EnemyType(Enum):
    Pneumococos = (
        "Pneumococos",
        1,
        0.8,
        None
    )
    Staphylococcus = (
        "Staphylococcus",
        1,
        1,
        None
    )
    Streptococcus = (
        "Streptococcus",
        1,
        0.9,
        None
    )


class Enemy(Sprite):
    def __init__(self, game, enemy: EnemyType, x, y):
        name, scale, shift, action = enemy.value
        super().__init__(game, name, x, y, scale, shift, action)
        self.sprite_update = super().update

        self.enemy = enemy
        self.angle = 0

        self.speed = 150
        self.health = 100
        self.damage = 10

        self.time = 0
        self.attack_cooldown = 2

    def go_to(self, x, y, min_dist: None | int = None):
        dx, dy = x - self.x, y - self.y
        self.angle = math.atan2(dx, dy)
        if min_dist:
            if dx ** 2 + dy ** 2 <= min_dist ** 2:
                return True
        self.x += math.sin(self.angle) * self.speed * self.game.delta_time
        self.y += math.cos(self.angle) * self.speed * self.game.delta_time
        return False

    def seeing_player(self) -> bool:
        player_x, player_y = self.game.player.x, self.game.player.y
        sprite_x, sprite_y = self.x, self.y
        dx, dy = player_x - sprite_x, player_y - sprite_y

        player_dist = (np.sqrt(dx ** 2 + dy ** 2) // Tile_size)
        angle_ray = math.atan2(dy, dx)
        angle_ray = angle_to_fist(angle_ray)

        world_map = self.game.map.world_wall
        is_render = self.game.map.tiles_to_render

        return numba_seeing_player(sprite_x, sprite_y, player_dist, world_map, is_render, angle_ray)

    def update(self):
        self.time += self.game.delta_time
        if self.time > 1:
            self.time -= 1
        self.attack_cooldown -= self.game.delta_time

        if self.seeing_player():
            if self.go_to(self.game.player.x, self.game.player.y, 92):
                if self.attack_cooldown <= 0:
                    # self.game.player.health -= self.damage
                    print(self.enemy, "atacou!")
                    self.attack_cooldown = 2

        self.sprite_update()


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
