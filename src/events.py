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

    def __init__(self, game, any: Any = None):
        self.game: InGame = game
        self.any = any

        self.current_event = 0

    def clone(self) -> 'Event':
        evt = Event(self.game, self.any)
        # if hasattr(self, 'events'):
        #    evt.events = self.events.copy()
        evt.events = self.events.copy()
        return evt

    def add(self, event: list[tuple[Callable, Any]], run=False):
        self.events = [FuncArgs(*eve) for eve in event]
        if run:
            self.run()

    def update(self):
        can_pop, can_add = self.events[self.current_event]()
        if can_pop:
            self.current_event += 1
        if can_add:
            self.run()

    def run(self, *args):
        self.any = args if len(args) > 0 else self.any
        if len(self.events) > self.current_event:
            self.game.scheduler.add_dict(self, 0, self.update)

    def sleep(self, time):
        self.game.scheduler.add_dict(self, time, self.update)
        return True, False

    @staticmethod
    def wait(func: Callable, *args):
        return func(*args), True

    def restart(self, run=True):
        self.current_event = 0
        return False, run

    def go_to(self, event: int):
        self.current_event = event
        return False, True

    def IF(self, condition: Callable, *args):
        if condition(*args):
            return True, True
        self.current_event += 1
        return True, True

    def setattr(self, obj: Any, attr: str, value):
        if obj is None:
            obj = self.any[0]
        setattr(obj, attr, value)
        return True, True

    def MK_dig(self, dig: 'Dialogue'):
        self.game.dialogue_handler.add(
            dig,
            self.game.scheduler.add_dict,
            self, 0, self.run
        )
        return True, False

    def MK_move(self, obj: 'Player | Sprite', x, y, min_dist=5):
        if obj is None:
            obj = self.any
        dx, dy = x - obj.x, y - obj.y
        angle = math.atan2(dx, dy)
        if dx ** 2 + dy ** 2 <= min_dist ** 2:
            return True, True
        obj.x += math.sin(angle) * obj.speed * self.game.delta_time
        obj.y += math.cos(angle) * obj.speed * self.game.delta_time
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

    def debug(self):
        print('não args: ', self)
        print(self)
        return True, True
