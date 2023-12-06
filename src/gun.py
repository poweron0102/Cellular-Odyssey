from main import *

pg.mixer.init()
AttackSounds = [pg.mixer.Sound(f'assets/sounds/attc{i}.ogg') for i in range(4)]
DathSounds = {
    'Neutrophil': pg.mixer.Sound(f'assets/sounds/neu_mata.ogg')
}
for sound in AttackSounds:
    sound.set_volume(VOLUME)
for sound in DathSounds.values():
    sound.set_volume(VOLUME)


class Gun:
    def __init__(self, game: 'InGame'):
        self.game: 'InGame' = game

        if game.player.name == 'Erythrocyte':
            self.update = lambda: None
            return

        self._image = pg.image.load(f'assets/guns/{game.player.name}.png').convert_alpha()

    def update(self):
        attack_progress = min(
            0.5 - (self.game.player.attack_cooldown / self.game.player.player_type.value[5]),
            0.5 - (self.game.player.super_cooldown / self.game.player.player_type.value[7])
        ) * 90
        image: pg.Surface = pg.transform.rotate(self._image, attack_progress)

        self.game.screen.blit(image, ((RES[0] - image.get_width()) / 2, RES[1] - image.get_height() + 20))


def attack_neutrophil(player):
    for sprite in player.game.sprite_handler.sprites_seeing:
        if hasattr(sprite, 'enemy'):
            # if 320 < sprite.screen_x / SCALE_RES[0] < 960:
            if 427 < sprite.screen_x / SCALE_RES[0] < 853 and sprite.dist < Tile_size * 2:  # 1/3 da tela
                sprite.health -= player.damage
                random.choice(AttackSounds).play()
                if sprite.health <= 0:
                    player.game.sprite_handler.sprites.remove(sprite)
                    if random.random() < 0.05:
                        DathSounds['Neutrophil'].play()


def super_neutrophil(player):
    for sprite in player.game.sprite_handler.sprites_seeing:
        if hasattr(sprite, 'enemy'):
            if 320 < sprite.screen_x / SCALE_RES[0] < 960 and sprite.dist < Tile_size:
                sprite.health -= player.damage * 2
                random.choice(AttackSounds).play()
                if sprite.health <= 0:
                    player.game.sprite_handler.sprites.remove(sprite)
                    if random.random() < 0.05:
                        DathSounds['Neutrophil'].play()

