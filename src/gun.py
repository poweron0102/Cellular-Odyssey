from main import *

pg.mixer.init()
AttackSounds = [pg.mixer.Sound(f'assets/sounds/attc{i}.ogg') for i in range(13)]
OtherSounds = {
    'Neutrophil': pg.mixer.Sound(f'assets/sounds/neu_mata.ogg'),
    'Macrophage0': pg.mixer.Sound(f'assets/sounds/Macrophage.ogg'),
    'Macrophage1': pg.mixer.Sound(f'assets/sounds/Macrophage1.ogg'),
}
for sound in AttackSounds:
    sound.set_volume(VOLUME / 100)
for sound in OtherSounds.values():
    sound.set_volume(VOLUME / 100)


class Gun:
    def __init__(self, game: 'InGame'):
        self.game: 'InGame' = game

        if game.player.name == 'Erythrocyte':
            self.update = lambda: None
            return

        elif game.player.name == 'Neutrophil':
            self.update = self.update_neutrophil

        elif game.player.name == 'Macrophage':
            self.update = self.update_macrophage

        elif game.player.name == 'BCell':
            self.update = lambda: None  # todo

        else:
            print('ERROR: Invalid player name')

        self._image = pg.image.load(f'assets/guns/{game.player.name}.png').convert_alpha()

    def update(self):
        """
        The actual function will be changed in the __init__ method
        """
        pass

    def update_neutrophil(self):
        attack_progress = min(
            0.5 - (self.game.player.attack_cooldown / self.game.player.player_type.value[6]),
            0.5 - (self.game.player.super_cooldown / self.game.player.player_type.value[8])
        ) * 90
        image: pg.Surface = pg.transform.rotate(self._image, attack_progress)

        self.game.screen.blit(image, ((RES[0] - image.get_width()) / 2, RES[1] - image.get_height() + 20))

    def update_macrophage(self):
        attack_progress = (0.5 - (self.game.player.attack_cooldown / self.game.player.player_type.value[6])) * 90
        image: pg.Surface = pg.transform.scale_by(pg.transform.rotate(self._image, attack_progress), SCALE_RES[1])

        self.game.screen.blit(image, ((RES[0] - image.get_width()) / 2, RES[1] - image.get_height() + 20))


def attack_neutrophil(player):
    for sprite in player.game.sprite_handler.sprites_seeing:
        if hasattr(sprite, 'enemy'):
            if 427 < sprite.screen_x / SCALE_RES[0] < 853 and sprite.dist < Tile_size:
                sprite.health -= player.damage
                random.choice(AttackSounds).play()
                sprite.PlayAnimation('blood', 1, 0.35)
                if sprite.health <= 0:
                    player.game.sprite_handler.sprites.remove(sprite)
                    if random.random() < 0.05:
                        OtherSounds['Neutrophil'].play()


def super_neutrophil(player):
    for sprite in player.game.sprite_handler.sprites_seeing:
        if hasattr(sprite, 'enemy'):
            if 320 < sprite.screen_x / SCALE_RES[0] < 960 and sprite.dist < Tile_size:
                sprite.health -= player.damage * 2
                random.choice(AttackSounds).play()
                sprite.PlayAnimation('blood', 1, 0.35)
                if sprite.health <= 0:
                    player.game.sprite_handler.sprites.remove(sprite)
                    if random.random() < 0.05:
                        OtherSounds['Neutrophil'].play()


def attack_macrophage(player):
    for sprite in player.game.sprite_handler.sprites_seeing:
        if hasattr(sprite, 'enemy'):
            if 100 < sprite.screen_x / SCALE_RES[0] < 1100 and sprite.dist < Tile_size * 2:  #  4/6 da tela
                sprite.health -= player.damage
                random.choice(AttackSounds).play()
                sprite.PlayAnimation('blood', 1, 0.35)
                if sprite.health <= 0:
                    player.game.sprite_handler.sprites.remove(sprite)
                    if random.random() < 0.05:
                        OtherSounds['Macrophage0'].play()


def super_macrophage(player):
    evt = Event(player.game)
    signal = random.choice([1, -1])
    OtherSounds['Macrophage1'].play()
    evt.add([
        (evt.setattr, player, 'enable_input', False),
        (attack_macrophage, player),
        (evt.turn_to, signal * math.pi / 4, 4),
        (attack_macrophage, player),
        (evt.turn_to, signal * math.pi / 4, 4),
        (attack_macrophage, player),
        (evt.turn_to, signal * math.pi / 4, 4),
        (attack_macrophage, player),
        (evt.turn_to, signal * math.pi / 4, 4),
        (attack_macrophage, player),
        (evt.turn_to, signal * math.pi / 4, 4),
        (attack_macrophage, player),
        (evt.turn_to, signal * math.pi / 4, 4),
        (attack_macrophage, player),
        (evt.turn_to, signal * math.pi / 4, 4),
        (attack_macrophage, player),
        (evt.turn_to, signal * math.pi / 4, 4),
        (attack_macrophage, player),
        (evt.setattr, player, 'enable_input', True),
    ], True)
