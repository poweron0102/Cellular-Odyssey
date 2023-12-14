from main import *
import levels.vens as vens


def init(in_game: 'InGame'):
    vens.init(in_game)
    in_game.hud = Hud(in_game)

    evt = Event(in_game)
    evt.add([
        (evt.setattr, in_game.player, 'enable_input', False),
        (evt.dig, Dialogue(
            1,
            'You finally made it to the lungs. Now you can deliver the oxygen.'
            'and end this tutorial.',
            'Neutrophil_0',
        )),
        (in_game.new_game, 'level_selector', (1280, 720)),
    ])
    in_game.map.tile_set[12].action = evt.run


def loop(in_game: 'InGame'):
    vens.loop(in_game)
