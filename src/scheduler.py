from main import *


class Scheduler:
    def __init__(self, game):
        self.game: InGame = game
        self._times = []
        self._functions = []
        self._args = []

        self.functions_dict = {}

    def update(self):
        for index, function in enumerate(self._functions):
            if self._times[index] < self.game.run_time:
                function(*self._args[index])
                self._times.pop(index)
                self._functions.pop(index)
                self._args.pop(index)

        for key in list(self.functions_dict.keys()):
            time, function, args = self.functions_dict[key]
            if time < self.game.run_time:
                self.functions_dict.pop(key)
                function(*args)

    def add(self, time: int | float, function, *args):
        self._times.append(self.game.run_time + time)
        self._functions.append(function)
        self._args.append(args)

    def add_dict(self, key, time, function, *args):
        self.functions_dict[key] = (self.game.run_time + time), function, args

    def remove(self, function):
        index = self._functions.index(function)
        self._times.pop(index)
        self._functions.pop(index)
        self._args.pop(index)

    def remove_dict(self, key):
        self.functions_dict.pop(key)
