import numpy as np

from main import *


class Gun:
    def __init__(self, game: 'InGame'):
        self.game: 'InGame' = game

        if game.player.player_type == PlayerType.Erythrocyte:
            self.update = lambda: None
            return

        self._image = pg.image.load(f'assets/guns/{game.player.name}.png').convert_alpha()

    def update(self):
        attack_progress = min(
            0.5 - (self.game.player.attack_cooldown / self.game.player.player_type.value[5]),
            0.5 - (self.game.player.super_cooldown / self.game.player.player_type.value[7])
        ) * 90
        image: pg.Surface = pg.transform.rotate(self._image, attack_progress)

        self.game.screen.blit(image, ((RES[0] - image.get_width())/2, RES[1] - image.get_height() + 10))
