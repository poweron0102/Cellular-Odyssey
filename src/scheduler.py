from main import *


class Scheduler:
    def __init__(self, game):
        self.game: InGame = game
        self._times = []
        self._functions = []
        self._args = []

    def update(self):
        for index, function in enumerate(self._functions):
            if self._times[index] < self.game.run_time:
                if self._args[index]:
                    function(self._args[index])
                else:
                    function()

                self._times.pop(index)
                self._functions.pop(index)
                self._args.pop(index)

    def add(self, time, function, args=None):
        self._times.append(self.game.run_time + time)
        self._functions.append(function)
        self._args.append(args)

    def remove(self, function):
        index = self._functions.index(function)
        self._times.pop(index)
        self._functions.pop(index)
        self._args.pop(index)
