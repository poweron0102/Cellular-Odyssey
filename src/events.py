from main import *
from typing import Callable, Any


class FuncArgs:
    def __init__(self, func, *args):
        self.func = func
        self.args = args

    def __call__(self):
        return self.func(*self.args)


class Event:
    def __init__(self, game):
        self.game: InGame = game
        self.events: list[FuncArgs] = []
        self.game.scheduler.add_dict(self, 0, self.update)

    def add(self, event: list[tuple]):
        self.events = [FuncArgs(*eve) for eve in event]

    def update(self):
        func = self.events[0]
        can_pop, can_add = func()
        if can_pop:
            self.events.pop(0)
        if can_add:
            self.game.scheduler.add_dict(self, 0, self.update)

    def sleep(self, time):
        self.game.scheduler.add_dict(self, time, self.update)
        return True, False

    def MK_dig(self, dig: 'Dialogue'):
        self.game.dialogue_handler.add(
            dig,
            self.game.scheduler.add_dict,
            self, 0, dig
        )
        return True, False

    def MK_move(self, obj: 'Player | Sprite', dist: float, min_dist=5):
        dx = dist * math.cos(obj.ang) * self.game.delta_time
        dy = dist * math.sin(obj.ang) * self.game.delta_time
        if dx ** 2 + dy ** 2 <= min_dist ** 2:
            return True, True
        obj.x += dx
        obj.y += dy
        return False, True

    def MK_look_at(self, ang, speed=0.1, min_dist=0.1):
        if self.game.player.ang > ang:
            if self.game.player.ang - ang < min_dist:
                self.game.player.ang = ang
                return True, True
            self.game.player.ang -= speed * self.game.delta_time
        elif self.game.player.ang < ang:
            if ang - self.game.player.ang < min_dist:
                self.game.player.ang = ang
                return True, True
            self.game.player.ang += speed * self.game.delta_time
        return False, True


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
