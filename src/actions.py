from main import *

ACTIONS = {}


def add_action(func):
    ACTIONS[func.__name__] = func


class Actions:

    def __init__(self, game):
        self.game: InGame = game

    def do_action(self, action, *args):
        ACTIONS[action](self.game, args)

    def update(self):
        playerX = self.game.player.x
        playerY = self.game.player.y
        action = self.game.map.tile_action(playerX, playerY)
        if type(action) is str:
            # print(self.action)
            ACTIONS[action](self.game)


@add_action
def construction(game, *args):
    # print(args[0][0])
    if args[0][0].dist < 128 and game.player.interact:
        game.dialogue_handler.add(
            Dialogue(
                7,
                "Oh, i'm really sorry. but we are doing some construction.",
                "platelet",
                audio='construcao'
            )
        )
        game.dialogue_handler.add(
            Dialogue(
                2,
                "No way we can snappy by?",
                "ae3803pla",
                audio='jeitodepassar'
            )
        )
        game.dialogue_handler.add(
            Dialogue(
                10,
                "No way at all. You see, what happened was there as a bit of trouble so construction get delayed.\
                 I gest the delivery people had made a big mistake.",
                "platelet",
                audio='dellead'
            ),
            poped_func=lambda x: game.scheduler.add(*x), poped_arg=(
                5, lambda x: setattr(*x), (args[0][0], 'action', 'construction')
            )
        )
        args[0][0].action = None
