from main import *
from typing import Callable, Any


class FuncArgs:
    def __init__(self, func, *args):
        self.func = func
        self.args = args

    def __call__(self):
        return self.func(*self.args)


class Event:
    events: list[FuncArgs]

    def __init__(self, game):
        self.game: InGame = game

    def add(self, event: list[tuple], auto_schedule=True):
        self.events = [FuncArgs(*eve) for eve in event]
        if auto_schedule:
            self.auto_schedule()

    def update(self):
        can_pop, can_add = self.events[0]()
        if can_pop:
            self.events.pop(0)
        if can_add:
            self.auto_schedule()

    def auto_schedule(self):
        if len(self.events) > 0:
            self.game.scheduler.add_dict(self, 0, self.update)

    def sleep(self, time):
        self.game.scheduler.add_dict(self, time, self.update)
        return True, False

    def MK_setattr(self, obj: Any, attr: str, value):
        setattr(obj, attr, value)
        return True, True

    def MK_dig(self, dig: 'Dialogue'):
        self.game.dialogue_handler.add(
            dig,
            self.game.scheduler.add_dict,
            self, 0, self.auto_schedule
        )
        return True, False

    def MK_move(self, obj: 'Player | Sprite', x, y, min_dist=5):
        dx, dy = x - obj.x, y - obj.y
        obj.angle = math.atan2(dx, dy)
        if dx ** 2 + dy ** 2 <= min_dist ** 2:
            return True, True
        obj.x += math.sin(obj.angle) * obj.speed * self.game.delta_time
        obj.y += math.cos(obj.angle) * obj.speed * self.game.delta_time
        return False, True

    def MK_look_at(self, ang, speed=0.5, min_dist=0.01):
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
