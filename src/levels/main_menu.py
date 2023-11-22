from main import *
from buttons import Button


def init(game: Game):
    game.background = pg.image.load("assets/gui/tela_menu.png").convert()

    game.buttons = [
        Button(
            game.screen.get_width() // 2 - 160, game.screen.get_height() // 2,
            "New Game",
            func_click=lambda x: game.new_game(*x), arg_click=("new_game", RES)
        ),
        Button(
            game.screen.get_width() // 2 - 160, game.screen.get_height() // 2 + 100,
            "continue",
            func_click=game.new_game, arg_click="level_selector"
        ),
        Button(
            game.screen.get_width() // 2 - 160, game.screen.get_height() // 2 + 200,
            "Exit",
            func_click=exit
        )
    ]


def loop(game: Game):
    game.screen.blit(game.background, (0, 0))
    for button in game.buttons:
        button.update()
