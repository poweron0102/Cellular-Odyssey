from main import *


class Hud:
    def __init__(self, game):
        self.game: InGame = game

        self.offset_x = 10
        self.offset_y = 10
        self.img = pg.image.load("assets/hud/HUD.png").convert_alpha()
        self.current_face = 0
        self.faces_img = [
            pg.image.load(f"assets/hud/{self.game.player.name}_{x}.png").convert_alpha() for x in range(0, 2)
        ]

        # Variáveis do HUD
        self.antigen = 0
        self.antigen_max = 150

        self.health_color = (45, 212, 101)
        self.health_rect = (337, 18, 243, 50)

        self.antigen_color = (153, 54, 199)
        self.antigen_rect = (348, 108, 221, 46)

        self.background_color = (128, 128, 128)
        self.background_rect = (336, 17, 245, 137)

    def set_face(self, face: int):
        self.current_face = face

    def update(self):
        if self.game.player.name == 'Neutrophil':
            self.antigen += self.game.delta_time
            if self.antigen >= self.antigen_max:
                self.antigen = 0
                self.game.player.new_player(PlayerType.Macrophage)
        elif self.game.player.name == 'Macrophage':
            # antigen get added in the attack function
            if self.antigen >= self.antigen_max:
                self.antigen = 0
                self.game.player.new_player(PlayerType.BCell)
        elif self.game.player.name == 'BCell':
            self.antigen += self.game.delta_time
            if self.antigen >= self.antigen_max:
                print("Parabens, você ganhou!!!!!!!!")
                # todo: liberar a proxima fase
                self.game.new_game('main_menu', (1280, 720))

        if self.antigen >= self.antigen_max:
            self.antigen = 0
            self.game.player.new_player(PlayerType.Macrophage)


        # Drawing HUD
        img = pg.Surface((621, 171), pg.SRCALPHA)
        # background
        pg.draw.rect(img, self.background_color, self.background_rect)

        # health
        rect = pg.Rect(
            self.health_rect[0],
            self.health_rect[1],
            self.health_rect[2] * self.game.player.life_percent,
            self.health_rect[3]
        )
        pg.draw.rect(img, self.health_color, rect)

        # antigen
        rect = pg.Rect(
            self.antigen_rect[0],
            self.antigen_rect[1],
            self.antigen_rect[2] * self.antigen / self.antigen_max,
            self.antigen_rect[3]
        )
        pg.draw.rect(img, self.antigen_color, rect)

        # hud
        img.blit(self.img, (0, 0))
        img.blit(self.faces_img[self.current_face], (0, 0))

        self.game.screen.blit(
            pg.transform.scale_by(img, SCALE_RES[0] / 2),  # /2 pq a imagem é 2x maior que a resolução
            (self.offset_x, self.offset_y)
        )
