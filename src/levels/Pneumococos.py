import math
from main import *
import levels.organs as organs


def init(in_game: 'InGame'):
    in_game.player = Player(in_game, *to_map(14, 25.8), 180, PlayerType.BCell)
    organs.init(in_game)

    routes = [
        [to_map(4.5, 15.5), to_map(23.5, 15.5), to_map(23.5, 12.5), to_map(4.5, 12.5), to_map(4.5, 15.5)],
        [to_map(12.5, 4.5), to_map(12.5, 23.5), to_map(15.5, 23.5), to_map(15.5, 4.5), to_map(12.5, 4.5)],
    ]
    for index in range(20):
        route = random.choice(routes)
        in_game.scheduler.add(
            index * 5,
            in_game.sprite_handler.add,
            Enemy(
                in_game,
                EnemyType.Pneumococos,
                *route[0],
                route=route
            )
        )


def loop(in_game: 'InGame'):
    organs.loop(in_game)
