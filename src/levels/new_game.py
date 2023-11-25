import math
from main import *
import levels.organs as organs


def init(in_game: 'InGame'):
    organs.init(in_game, PlayerType.Erythrocyte)
    in_game.player.enable_input = False

    evt = Event(in_game)
    evt.add([
        (evt.MK_dig, Dialogue(
            7,
            "Oh, i'm really sorry. but we are doing some construction.",
            "platelet",
            audio='construcao'
        )),
        (evt.MK_dig, Dialogue(
            2,
            "No way we can snappy by?",
            "ae3803pla",
            audio='jeitodepassar'
        )),
        (evt.MK_dig, Dialogue(
            10,
            "No way at all. You see, what happened was there as a bit of trouble so construction get delayed.\
             I gest the delivery people had made a big mistake.",
            "platelet",
            audio='dellead'
        )),
        (evt.setattr, None, 'action', evt.run),
        (evt.restart, False),
    ])
    in_game.sprite_handler.add(Sprite(in_game, 'platelet', *to_map(10.5, 11.5), action=evt.run))

    evt = Event(in_game)
    evt.add([
        (evt.sleep, 1),
        (evt.MK_move, in_game.player, *to_map(14, 26.2)),
        (evt.sleep, 1),
        (evt.MK_dig, Dialogue(
            2,
            'Ah, i cant get lost again, i need to find the way to the lungs.',
            'AE3803',
        )),
        (evt.MK_dig, Dialogue(
            2,
            'I think i find it, it should be this way.',
            'AE3803',
        )),
        (evt.MK_move, in_game.player, *to_map(14, 23.5)),
        (evt.MK_look_at, math.radians(90), 1),
        (evt.setattr, in_game.player, 'enable_input', True),
        (evt.wait, lambda: in_game.player.x <= 18 * Tile_size),
        (evt.MK_dig, Dialogue(
            2,
            'What is this? A Pneumococos? Ah!!!!',
            'AE3803',
        )),
    ], True)


def loop(in_game: 'InGame'):
    organs.loop(in_game)
