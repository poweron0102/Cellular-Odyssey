import math
from main import *
import levels.organs as organs


def init(in_game: 'InGame'):
    if not hasattr(in_game, 'player'):
        in_game.player = Player(in_game, *to_map(14, 25.8), 180, PlayerType.Neutrophil)
        in_game.hud = Hud(in_game)
        in_game.gun = Gun(in_game)

    organs.init(in_game)

    in_game.map.tile_set[8].action = lambda x: in_game.new_game('Svens')

    routes = [
        [to_map(4.5, 15.5), to_map(23.5, 15.5), to_map(23.5, 12.5), to_map(4.5, 12.5), to_map(4.5, 15.5)],
        [to_map(12.5, 4.5), to_map(12.5, 23.5), to_map(15.5, 23.5), to_map(15.5, 4.5), to_map(12.5, 4.5)],
    ]
    for index in range(10):
        route = random.choice(routes)
        in_game.scheduler.add(
            index * 9,
            in_game.sprite_handler.add,
            Enemy(
                in_game,
                EnemyType.Staphylococcus,
                *route[0],
                route=route
            )
        )


def loop(in_game: 'InGame'):
    organs.loop(in_game)
