from main import *
from typing import Callable, Any


class FuncArgs:
    def __init__(self, func, *args):
        self.func = func
        self.args = args

    def __call__(self):
        return self.func(*self.args)


class Event:
    def __init__(self, game, is_sleeping=False):
        self.game: InGame = game
        self.is_sleeping = is_sleeping
        self.events: list[list[FuncArgs]] = []

    def add(self, event: list[tuple]):
        self.events.append([FuncArgs(*eve) for eve in event])

    def sleep(self):
        self.is_sleeping = True

    def wake_up(self):
        self.is_sleeping = False

    def update(self):
        if self.is_sleeping:
            return
        for index, event in enumerate(self.events):
            comp = event[0]()
            if comp == True or comp == None:
                return
            event.pop(0)
            if len(event) == 0:
                self.events.pop(index)

"""
e = Events()
e.add([
    (lambda: print('oi'),),
    (lambda: print('oi2'),),
    (lambda: print('oi7'),),
    (print, 'Nathan'),
    (print, "Nathan", "é", "legal"),
])

while True:
    e.update()
    input()
"""
