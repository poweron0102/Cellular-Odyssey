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
        self.health = 100
        self.damage = 10

