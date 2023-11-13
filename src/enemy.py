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
        self.enemy = enemy
        self.angle = 0

        self.speed = 150
        self.health = 100
        self.damage = 10

    def go_to(self, x, y, min_dist: None | int = None):
        # self.angle = math.atan2(x - self.x - self.width/self.dist, y - self.y)
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

        dx, dy = sprite_x - player_x, sprite_y - player_y
        player_dist = (np.sqrt(dx ** 2 + dy ** 2) // Tile_size) + 1
        world_map = self.game.map.world_wall
        is_render = self.game.map.tiles_to_render
        angle_ray = math.atan2(dx, dy)

        pg.draw.circle(self.game.screen,
                       'white',
                       ((Mine_Map_zoom * sprite_x / Tile_size) + Mini_Map_position[0],
                        (Mine_Map_zoom * sprite_y / Tile_size) + Mini_Map_position[1]),
                       4
                       )
        pg.draw.circle(self.game.screen,
                       (78, 45, 177),
                       ((Mine_Map_zoom * player_x / Tile_size) + Mini_Map_position[0],
                        (Mine_Map_zoom * player_y / Tile_size) + Mini_Map_position[1]),
                       4
                       )
        pg.draw.circle(self.game.screen,
                       (255, 45, 177),
                       ((Mine_Map_zoom * (sprite_x + np.cos(angle_ray)*20) / Tile_size) + Mini_Map_position[0],
                        (Mine_Map_zoom * (sprite_y + np.sin(angle_ray)*20) / Tile_size) + Mini_Map_position[1]),
                       4
                       )

        a_tan = 1 / (np.tan(angle_ray) + 0.00001)
        rendist = 0
        if angle_ray > np.pi:  # looking up
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
                    pg.draw.circle(self.game.screen,
                                   'red',
                                   ((Mine_Map_zoom * ray_x / Tile_size) + Mini_Map_position[0],
                                    (Mine_Map_zoom * ray_y / Tile_size) + Mini_Map_position[1]),
                                   4
                                   )
                    if world_map[y][x] in is_render:
                        return False
            # else:
            ray_x += offset_x
            ray_y += offset_y
            rendist += 1

        # Calculo vertical -=-=-=-=-=-=-=-=-=-=
        rendist = 0
        a_tan = np.tan(angle_ray)
        if angle_ray < np.pi / 2 or angle_ray > np.pi * 3 / 2:  # looking right
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
                    pg.draw.circle(self.game.screen,
                                   'blue',
                                   ((Mine_Map_zoom * ray_x / Tile_size) + Mini_Map_position[0],
                                    (Mine_Map_zoom * ray_y / Tile_size) + Mini_Map_position[1]),
                                   4
                                   )
                    if world_map[y][x] in is_render:
                        return False
            # else:
            ray_x += offset_x
            ray_y += offset_y
            rendist += 1

        return True
