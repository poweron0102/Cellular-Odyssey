from pygame import SurfaceType

from main import *


class Dialogue:
    def __init__(self, time, dialogue: str, speaker: str, audio=None, font='fonts/Roboto-Thin.ttf', size=25,
                 name_size=18):
        self.frame_x = 0
        self.frame_y = 490 * SCALE_RES[1]

        self.font = pg.font.Font(font, int(size * SCALE_RES[0] + 0.5))
        self.name_font = pg.font.Font(font, name_size)
        name_img = self.name_font.render(speaker, False, [0, 0, 0], None)

        self.image = pg.image.load("assets/dialogue/frame.png").convert_alpha()

        speaker = pg.image.load(f"assets/dialogue/{speaker}.png").convert_alpha()
        self.image.blits(((speaker, (45, 51)), (name_img, (46, 11))))

        self.image = pg.transform.scale_by(self.image, SCALE_RES[0])

        self.passed_time = 0
        self.max_time = time * 1000

        self.dialogue: list[str | None] = dialogue.split()
        self.current_line = 0
        self.falado_line: list[str] = ['']
        self.text_imgs: list[None | SurfaceType] = [None]

        self.final_img = None

        self.audio = audio

    def update(self, game):
        if self.passed_time == 0:
            if self.audio:
                sound = pg.mixer.Sound(f'assets/dialogue/sound/{self.audio}.ogg')
                sound.play()

                sound.set_volume(VOLUME / 100)

        if self.passed_time < self.max_time:
            # print(round(len(self.dialogue) * (self.passed_time / self.max_time) + 0.5))
            if game.player.interact:
                self.passed_time += self.max_time//len(self.dialogue)
                if self.passed_time >= self.max_time:
                    self.passed_time = self.max_time - 0.01
            dialog_id = int(len(self.dialogue) * (self.passed_time / self.max_time))
            if current_dialogue := self.dialogue[dialog_id]:
                self.falado_line[self.current_line] += current_dialogue + ' '

                self.dialogue[dialog_id] = None

                font_size = self.font.size(self.falado_line[self.current_line])
                if font_size[0] > 1100 * SCALE_RES[0]:
                    self.current_line += 1
                    self.text_imgs.append(None)
                    self.falado_line.append(current_dialogue + ' ')

                self.text_imgs[self.current_line] = self.font.render(
                    self.falado_line[self.current_line],
                    False,
                    [0, 0, 0],
                    None
                )

                self.final_img = self.image.copy()
                for i, text_img in enumerate(self.text_imgs):
                    self.final_img.blit(text_img, (158 * SCALE_RES[0], 46 * SCALE_RES[1] + font_size[1] * i))

            game.drawer.to_draw.append((4, (self.final_img, self.frame_x, self.frame_y)))

        else:
            if game.player.interact:
                game.dialogue_handler.pop()
                self.passed_time = 0
                self.max_time = 0.1
            game.drawer.to_draw.append((4, (self.final_img, self.frame_x, self.frame_y)))

        self.passed_time += game.delta_time * 1000



class DialogueHandler:
    def __init__(self, game):
        self.game: Game = game
        self._queue: list[Dialogue | None] = []
        self._queue_funcs: list = []
        self._queue_args: list = []

    def update(self):
        if len(self._queue) > 0:
            self._queue[0].update(self.game)

    def add(self, dig: Dialogue, poped_func=None, *args):
        self._queue.append(dig)
        self._queue_funcs.append(poped_func)
        self._queue_args.append(args)

    def pop(self):
        self._queue.pop(0)
        if func := self._queue_funcs.pop(0):
            func(*self._queue_args.pop(0))
        else:
            self._queue_args.pop(0)

