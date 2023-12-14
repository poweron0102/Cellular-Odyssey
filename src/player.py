import numpy as np

from main import *


class PlayerType(Enum):
    # name, speed, health, regenerate, damage, attack_func, attack_cooldown, super_func, super_cooldown
    Erythrocyte = 'Erythrocyte', 200, 100, 0, 0, attack_neutrophil, 1, attack_neutrophil, 1
    Neutrophil = 'Neutrophil', 200, 100, 5, 20, attack_neutrophil, 0.5, super_neutrophil, 1
    Macrophage = 'Macrophage', 150, 250, 8, 50, attack_macrophage, 1.5, super_macrophage, 15
    BCell = 'BCell', 200, 75, 2, 10, attack_b_cell, 0.3, super_b_cell, 10


class Player:
    def __init__(self, game, x, y, ang, player_type: PlayerType, enable_input=True):
        self.game: InGame = game

        self.x = x
        self.y = y
        self.ang = math.radians(ang)

        self.player_type = player_type
        name, speed, health, regenerate, damage, attack_func, attack_cooldown, super_func, super_cooldown = player_type.value
        self.name = name
        self.speed = speed
        self.health = health
        self.regenerate = regenerate
        self.max_health = health
        self.damage = damage

        self.attack_func = attack_func
        self.attack_cooldown = attack_cooldown
        self.attack_cooldown_r = attack_cooldown

        self.super_func = super_func
        self.super_cooldown = super_cooldown
        self.super_cooldown_r = super_cooldown

        self.enable_input = enable_input

        self.xray = False
        self.open_map = False
        self.interact = False
        self.debug = False
        self.keys = pg.key.get_pressed()

    def update(self):
        self.health = min(self.health + (self.regenerate * self.game.delta_time), self.max_health)
        self.attack_cooldown = max(self.attack_cooldown - self.game.delta_time, 0)
        self.super_cooldown = max(self.super_cooldown - self.game.delta_time, 0)

        tile = self.game.map.tile(self.x, self.y)
        if tile.action:
            tile.action(tile, *tile.action_args)
            tile.action = None

        if self.health < 0:
            self.game.new_game('game_over', (1280, 720))

        # Movimento WASD  -=-=-=-=-=-=-=-=-=-=-=-=-=-=
        keys = pg.key.get_pressed()
        dx = 0
        dy = 0
        speed = self.speed * self.game.delta_time

        mouse_move = pg.mouse.get_rel()  # to avoid mouse teleporting

        if self.enable_input:
            if keys[pg.K_w]:
                dx += speed * math.cos(self.ang)
                dy += speed * math.sin(self.ang)
            if keys[pg.K_d]:
                dx += speed * math.cos(self.ang + (math.pi / 2))
                dy += speed * math.sin(self.ang + (math.pi / 2))
            if keys[pg.K_a]:
                dx += (speed * math.sin(self.ang + math.pi)) * -1
                dy += speed * math.cos(self.ang + math.pi)
            if keys[pg.K_s]:
                dx += speed * math.sin(self.ang + (3 * math.pi / 2))
                dy += (speed * math.cos(self.ang + (3 * math.pi / 2))) * -1
            # Movimento WASD  -=-=-=-=-=-=-=-=-=-=-=-=-=-=

            # Movimento Mouse -=-=-=-=-=-=-=-=-=-=-=-=-=-=
            mouse_pos = pg.mouse.get_pos()
            if mouse_pos[0] < 10:
                pg.mouse.set_pos(RES[0] - 30, mouse_pos[1])

            if mouse_pos[0] > RES[0] - 10:
                pg.mouse.set_pos(30, mouse_pos[1])

            if pg.mouse.get_pressed()[0] and self.attack_cooldown <= 0:
                self.attack_func(self)
                self.attack_cooldown = self.attack_cooldown_r
            elif pg.mouse.get_pressed()[2] and self.super_cooldown <= 0:
                self.super_func(self)
                self.super_cooldown = self.super_cooldown_r

            self.ang += mouse_move[0] * Mouse_sens
            if self.ang > 2 * math.pi:
                self.ang -= 2 * math.pi
            if self.ang < 0:
                self.ang += 2 * math.pi
            # Movimento Mouse -=-=-=-=-=-=-=-=-=-=-=-=-=-=

            if not self.game.map.is_wall(self.x + dx * 4, self.y):
                self.x += dx

            if not self.game.map.is_wall(self.x, self.y + dy * 4):
                self.y += dy

        # Outros -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        if keys[pg.K_e] and not self.keys[pg.K_e]:
            self.interact = True
        else:
            self.interact = False

        if keys[pg.K_0] and not self.keys[pg.K_0]:
            self.debug = True
            print("Player: ", self.x, self.y)
            print("Player mod: ", self.x // Tile_size, self.y // Tile_size)
        else:
            self.debug = False

        if keys[pg.K_ESCAPE] and not self.keys[pg.K_ESCAPE]:
            self.game.scheduler.add_dict('exit', 1.5, self.game.new_game, 'main_menu', (1280, 720))
        if not keys[pg.K_ESCAPE] and self.keys[pg.K_ESCAPE]:
            self.game.scheduler.remove_dict('exit')

        if keys[pg.K_m] and not self.keys[pg.K_m]:
            self.open_map = not self.open_map

        if keys[pg.K_x] and not self.keys[pg.K_x]:
            self.xray = not self.xray

        # Outros -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

        self.keys = keys

        if self.open_map:
            self.game.drawer.to_draw.extend([
                (2, self.game.map),
                (1, self)
            ])

    def new_player(self, player_type: PlayerType):
        self.__init__(self.game, self.x, self.y, np.degrees(self.ang), player_type, True)
        self.game.hud.__init__(self.game)
        self.game.gun.__init__(self.game)

    @property
    def life_percent(self):
        return self.health / self.max_health

    def calc_linha(self, x, y, tamanho):
        return x + (tamanho * math.cos(self.ang)), y + (tamanho * math.sin(self.ang))

    def calc_linha_centro(self, tamanho):
        return RES[0] / 2 + (tamanho * math.cos(self.ang)), RES[1] / 2 + (tamanho * math.sin(self.ang))
