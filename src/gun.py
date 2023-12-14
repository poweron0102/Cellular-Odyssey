from main import *

pg.mixer.init()
AttackSounds = [pg.mixer.Sound(f'assets/sounds/attc{i}.ogg') for i in range(13)]
OtherSounds = {
    'Neutrophil': pg.mixer.Sound(f'assets/sounds/neu_mata.ogg'),
    'Macrophage0': pg.mixer.Sound(f'assets/sounds/Macrophage.ogg'),
    'Macrophage1': pg.mixer.Sound(f'assets/sounds/Macrophage1.ogg'),
    'BCell0': pg.mixer.Sound(f'assets/sounds/BCell.ogg'),
    'BCell1': pg.mixer.Sound(f'assets/sounds/BCell1.ogg'),
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
            self.update = self.update_b_cell

        else:
            print('ERROR: Invalid player name')

        self.image: pg.Surface = pg.image.load(f'assets/guns/{game.player.name}.png').convert_alpha()

    def update(self):
        """
        The actual function will be changed in the __init__ method
        """
        pass

    def update_neutrophil(self):
        attack_progress = min(
            0.5 - (self.game.player.attack_cooldown / self.game.player.attack_cooldown_r),
            0.5 - (self.game.player.super_cooldown / self.game.player.super_cooldown_r)
        ) * 90
        image: pg.Surface = pg.transform.rotate(self.image, attack_progress)

        self.game.screen.blit(image, ((RES[0] - image.get_width()) / 2, RES[1] - image.get_height() + 20))

    def update_macrophage(self):
        attack_progress = (0.5 - (self.game.player.attack_cooldown / self.game.player.attack_cooldown_r)) * 90
        image: pg.Surface = pg.transform.scale_by(pg.transform.rotate(self.image, attack_progress), SCALE_RES[1])

        self.game.screen.blit(image, ((RES[0] - image.get_width()) / 2, RES[1] - image.get_height() + 20))

    def update_b_cell(self):
        attack_progress = (self.game.player.attack_cooldown_r - self.game.player.attack_cooldown) / \
                          self.game.player.attack_cooldown_r
        super_progress = (self.game.player.super_cooldown_r - self.game.player.super_cooldown) / \
                         self.game.player.super_cooldown_r

        image: pg.Surface = pg.Surface((self.image.get_width(), self.image.get_height()), pg.SRCALPHA)

        pg.draw.rect(
            image,
            (128, 128, 128),
            (66, 186, 77, 17)
        )
        pg.draw.rect(
            image,
            (53, 255, 44) if super_progress > 0.96 else (255, 53, 44),
            (66, 186, 77 * super_progress, 17)
        )

        image.blit(self.image, (0, 0))
        image = pg.transform.scale_by(image, SCALE_RES[1])

        self.game.screen.blit(
            image, (
                (RES[0] - image.get_width()) / 2,
                RES[1] - image.get_height() + 20 - 10 * attack_progress
            )
        )


def attack_neutrophil(player):
    for sprite in player.game.sprite_handler.sprites_seeing:
        if hasattr(sprite, 'enemy'):
            if 427 < sprite.screen_x / SCALE_RES[0] < 853 and sprite.dist < Tile_size * 1.5:
                sprite.health -= player.damage
                random.choice(AttackSounds).play()
                sprite.PlayAnimation('blood', 1, 0.35)
                if sprite.health <= 0:
                    sprite.kill()
                    if random.random() < 0.05:
                        OtherSounds['Neutrophil'].play()


def super_neutrophil(player):
    for sprite in player.game.sprite_handler.sprites_seeing:
        if hasattr(sprite, 'enemy'):
            if 320 < sprite.screen_x / SCALE_RES[0] < 960 and sprite.dist < Tile_size * 1.5:
                sprite.health -= player.damage * 2
                random.choice(AttackSounds).play()
                sprite.PlayAnimation('blood', 1, 0.35)
                if sprite.health <= 0:
                    sprite.kill()
                    if random.random() < 0.05:
                        OtherSounds['Neutrophil'].play()


def attack_macrophage(player):
    for sprite in player.game.sprite_handler.sprites_seeing:
        if hasattr(sprite, 'enemy'):
            if 100 < sprite.screen_x / SCALE_RES[0] < 1100 and sprite.dist < Tile_size * 2:  # 4/6 da tela
                sprite.health -= player.damage
                random.choice(AttackSounds).play()
                sprite.PlayAnimation('blood', 1, 0.35)
                if sprite.health <= 0:
                    sprite.kill()
                    player.game.hud.antigen += 10
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


def attack_b_cell(player):
    player.game.sprite_handler.sprites_seeing.sort(key=lambda x: x.dist)
    for sprite in player.game.sprite_handler.sprites_seeing:
        if hasattr(sprite, 'enemy'):
            if 573 < sprite.screen_x / SCALE_RES[0] < 707 and sprite.seeing_player():
                sprite.health -= player.damage
                random.choice(AttackSounds).play()
                sprite.PlayAnimation('blood', 1, 0.35)
                if sprite.health <= 0:
                    sprite.kill()
                    if random.random() < 0.05:
                        OtherSounds['BCell0'].play()
                else:  # se o inimigo morrer, pode atacar outro
                    break  # só pode atacar um inimigo por vez
        else:
            if 603 < sprite.screen_x / SCALE_RES[0] < 677:
                break


def super_b_cell(player):
    OtherSounds['BCell1'].play()
    player.attack_cooldown_r = 0.1
    player.game.scheduler.add(
        5,
        lambda: setattr(player, 'attack_cooldown_r', player.player_type.value[6])
    )
