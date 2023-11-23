from main import *


class PlayerType(Enum):
    # speed, health, damage, attack_func
    Erythrocyte = 'Erythrocyte', 200, 200, 0, None
    Neutrophil = 'Neutrophil', 200, 200, 10, None
    Macrophage = 'Macrophage', 150, 500, 25, None
    BCell = 'BCell', 200, 200, 10, None


class Player:
    def __init__(self, game, x, y, ang, player_type: PlayerType, enable_input=True):
        self.game: InGame = game

        self.x = x
        self.y = y
        self.ang = math.radians(ang)

        self.player_type = player_type
        name, speed, health, damage, attack_func = player_type.value
        self.name = name
        self.speed = speed
        self.health = health
        self.max_health = health
        self.damage = damage
        self.attack_func = attack_func

        self.enable_input = enable_input

        self.xray = False
        self.open_map = False
        self.interact = False
        self.debug = False
        self.keys = pg.key.get_pressed()

    def update(self):
        self.health = min(self.health + self.game.delta_time, self.max_health)

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

    @property
    def life_percent(self):
        return self.health / self.max_health

    def calc_linha(self, x, y, tamanho):
        return x + (tamanho * math.cos(self.ang)), y + (tamanho * math.sin(self.ang))

    def calc_linha_centro(self, tamanho):
        return RES[0] / 2 + (tamanho * math.cos(self.ang)), RES[1] / 2 + (tamanho * math.sin(self.ang))
