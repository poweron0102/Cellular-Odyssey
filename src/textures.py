import pygame as pg
from pygame import Surface


class Texture:
    def __init__(self, name: str):
        name = name.split()
        to_load = [pg.image.load(f'assets/walls/{name[0]}.png').convert()] * 4
        for id, texture_name in enumerate(name[1:]):
            if texture_name == 'none':
                continue
            to_load[id + 1] = pg.image.load(f'assets/walls/{texture_name}.png').convert()

        self._texture: list[Surface] = to_load
        self.modify = None

    def texture(self, look=0) -> Surface:
        if self.modify:
            t = self._texture[look].copy()
            t.blit(self.modify, (0, 0))
            return t
        return self._texture[look]

    def texture_array(self, look=0):
        return pg.surfarray.pixels3d(self.texture(look=look))


class AnimatedTexture(Texture):
    def __init__(self, names: list[str], time=1):
        self.time = 0
        self.time_per_frame = time

        self.current_freme = 0
        self.frames: list[Texture] = []
        for name in names:
            self.frames.append(Texture(name))

    def update(self, delta_time):
        self.time += delta_time
        self.current_freme = int(self.time/self.time_per_frame)
        if self.current_freme >= len(self.frames):
            self.current_freme = 0
            self.time = 0

    def texture(self, look=0):
        return self.frames[self.current_freme].texture(look=look)

    def texture_array(self, look=0):
        return self.frames[self.current_freme].texture_array(look=look)



