from main import *
import levels.vens as vens


def init(in_game: 'InGame'):
    vens.init(in_game)
    evt = Event(in_game)
    evt.add([
        (in_game.new_game, 'Staphylococcus')
    ])
    in_game.map.tile_set[12].action = evt.run


def loop(in_game: 'InGame'):
    vens.loop(in_game)
