import sys
from types import ModuleType
from enum import Enum
from importlib import import_module
import pygame as pg
import numpy as np
from numba import njit
import math
import random

from settings import *
from functions import *
from in_game import *
from textures import *
from parallax import *
from map import *
from player import *
from ray_caster import *
from dialogue import *
from sprites import *
from enemy import *
from drawer import *
from actions import *


class NewGame(Exception):
    """Exception raised for handle new games."""
    # Isso com claramente não é uma gambiarra.
    pass


def check_events():
    for event in pg.event.get():
        if event.type == pg.QUIT:  # or (event.type == pg.KEYDOWN and event.key == pg.k_ESCAPE):
            pg.quit()
            sys.exit()


class Game:
    level: ModuleType

    def __init__(self):
        pg.init()
        pg.font.init()
        if FULLSCREEN:
            self.screen = pg.display.set_mode((1280, 720), pg.FULLSCREEN)
        else:
            self.screen = pg.display.set_mode((1280, 720))

        self.clock = pg.time.Clock()
        self.time = pg.time.get_ticks()
        self.lest_time = pg.time.get_ticks()
        self.delta_time = 0
        self.new_game("level_selector", supress=True)
        # pg.mouse.set_visible

    def new_game(self, level: str, set_screen=None, supress=False):
        if set_screen:
            # print(level, set_screen)
            self.screen = pg.display.set_mode(set_screen)
            self.screen.blit(pg.transform.scale(pg.image.load("assets/gui/load.png"), set_screen), (0, 0))
            pg.display.flip()
            if FULLSCREEN and not pg.display.get_surface().get_flags() & pg.FULLSCREEN:
                pg.display.toggle_fullscreen()

        self.level = import_module(f".{level}", "levels")
        self.level.init(self)
        if not supress:
            raise NewGame

    def update(self):
        pg.display.flip()
        self.screen.fill((0, 0, 0))  # preto
        self.clock.tick(FPS)
        self.lest_time = self.time
        self.time = pg.time.get_ticks()
        self.delta_time = (self.time - self.lest_time) / 1000.0
        pg.display.set_caption(f'Cellular Odyssey   FPS: {self.clock.get_fps() :.1f}')

    def run(self):
        while True:
            check_events()
            self.update()
            try:
                self.level.loop(self)
            except NewGame:
                pass


if __name__ == '__main__':
    game = Game()
    game.run()