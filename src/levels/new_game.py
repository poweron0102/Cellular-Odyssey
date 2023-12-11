import math
from main import *
import levels.organs as organs


def init(in_game: 'InGame'):
    in_game.player = Player(in_game, *to_map(14, 25.8), 180, PlayerType.Erythrocyte)
    organs.init(in_game)
    in_game.player.enable_input = False

    macrophage = Sprite(
        in_game,
        'Macrophage',
        *to_map(10.3, 23.5),
        0.8,
        0.5,
    )
    pneumococos = Sprite(
        in_game,
        'Pneumococos',
        *to_map(14, 14),
        0.8,
        0.5,
    )
    neutrophil = Sprite(
        in_game,
        'Neutrophil',
        *to_map(8, 14),
        0.8,
        0.5,
    )

    evt = Event(in_game)
    evt.add([
        # compilação
        (evt.sleep, 1),
        (evt.move, in_game.player, *to_map(14, 25.7)),
        (evt.sleep, 1),
        # Macrófago
        (evt.dig, Dialogue(
            6,
            'I better hurry and deliver this to the lungs. Ok, just need to turn rigth here to get to the lungs.',
            'AE3803',
            'tothelungs'
        ), True),
        (evt.move, in_game.player, *to_map(14, 23.5), 5, 100),
        (evt.look_at, math.radians(270), 0.6),
        (evt.move, in_game.player, *to_map(10.8, 23.5), 5, 100),
        (evt.sleep, 0.5),
        (in_game.sprite_handler.add_dict, macrophage, macrophage),
        (evt.move, in_game.player, *to_map(12.5, 23.5)),
        (evt.dig, Dialogue(
            2,
            'Oh, I am sorry, but this the spleen sweetie.',
            'Macrophage_0',
            'baco'
        )),
        (evt.dig, Dialogue(
            2,
            'Spleen?, I thought I was going to the lungs. Sorry, I am new here.',
            'AE3803',
        )),
        (evt.sleep, 1),
        (in_game.sprite_handler.remove_dict, macrophage),
        (evt.setattr, in_game.player, 'enable_input', True),

        # Pneumococos
        (evt.wait, lambda: in_game.player.x <= 16.5 * Tile_size),
        (evt.setattr, in_game.player, 'enable_input', False),
        (in_game.sprite_handler.add_dict, pneumococos, pneumococos),
        (evt.look_to, *to_map(14, 14), 2),
        (evt.dig, Dialogue(
            2,
            'What is this? A Pneumococos? Ah!!!!',
            'AE3803',
        )),
        (evt.dig, Dialogue(
            16,
            'Well now this is a delightful spot to my brother and I get really comfortable in here.'
            'It is not to hot, not to cold, and there is plenty of food to last more than a life cycle.'
            'This world belongs to us',
            'todo',  # TODO: Pneumococos_0
            'pneumosay'
        )),
        (in_game.sprite_handler.add_dict, neutrophil, neutrophil),
        (evt.move, neutrophil, *to_map(14, 14), 32, 200),
        (evt.dig, Dialogue(
            4,
            'Die, you germ! Take that!',
            'todo',  # TODO:
            'neutropilo1'
        ), True),
        (evt.sleep, 1),
        (pneumococos.PlayAnimation, 'blood', 2, 0.3),
        (evt.sleep, 2),
        (in_game.sprite_handler.remove_dict, pneumococos),
        (evt.dig, Dialogue(
            4,
            'Here is white blood cell, Neutrophil division U1146. The invader germs has been eliminated.',
            'todo',  # TODO:
            'neutropilo2'
        )),
        (evt.dig, Dialogue(
            2,
            'The white blood cell is so strong. I am glad I am not a germ.',
            'AE3803',
        )),
        (evt.dig, Dialogue(
            2,
            'Hi Red Blood Cell, I am Neutrophil, a white blood cell. I am here to protect you.',
            'todo'  # TODO:
        )),
        (evt.dig, Dialogue(
            4,
            'Well i just wanna to thank you for saving my life. I was in so much danger.',
            'AE3803',
            'save-mylife'
        )),
        (evt.dig, Dialogue(
            4,
            'That was nothing, I was only carrying out my job. Ahh, sorry i mean, you are welcome.',
            'todo',  # TODO:
            'thatwasonlymyjob'
        )),
        (evt.dig, Dialogue(
            2,
            'They a going to the lungs. I should stop them.',
            'todo'  # TODO:
        )),
        (evt.dig, Dialogue(
            2,
            'I am going to the lungs too. I should follow you.',
            'AE3803'
        )),
        (evt.dig, Dialogue(
            2,
            'Ok, the lungs are this way.',
            'todo'  # TODO:
        )),
        (evt.move, neutrophil, *to_map(15, 2), 20, 200),


        (evt.setattr, in_game.player, 'enable_input', True),
    ], True)

    evt = Event(in_game)
    evt.add([
        (evt.wait, lambda: 2.5 >= in_game.player.y / Tile_size and 13 <= in_game.player.x / Tile_size <= 15),
        (evt.setattr, in_game.player, 'enable_input', False),
        (evt.dig, Dialogue(
            2,
            'I should follow the White Blood Cell to the lungs.',
            'AE3803',
        ), True),
        (evt.look_to, *to_map(4.5, 14), 2, 0.2),
        (evt.move, in_game.player, *to_map(4.5, 14), 20),
        (evt.setattr, in_game.player, 'enable_input', True),
        (evt.restart, True)
    ], True)

    evt = Event(in_game)
    evt.add([
        (evt.wait, lambda: 25.5 <= in_game.player.y / Tile_size and 13 <= in_game.player.x / Tile_size <= 15),
        (evt.setattr, in_game.player, 'enable_input', False),
        (evt.dig, Dialogue(
            2,
            'I should follow the White Blood Cell to the lungs.',
            'AE3803',
        ), True),
        (evt.look_to, *to_map(24.5, 14), 2, 0.2),
        (evt.move, in_game.player, *to_map(24.5, 14), 20),
        (evt.setattr, in_game.player, 'enable_input', True),
        (evt.restart, True)
    ], True)


def loop(in_game: 'InGame'):
    organs.loop(in_game)
