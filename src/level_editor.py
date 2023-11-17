import pygame as pg
import numpy as np

pg.init()
screen = pg.display.set_mode((800, 600))

level_img = pg.image.load("new_level.png").convert()
level_matrix = pg.surfarray.pixels3d(level_img)

convert: dict[np.array, int] = {}


for index, color in enumerate(level_matrix[0]):
    color = tuple(color)
    if color in convert.keys():
        break
    convert[color] = index

print("convert = {")
for k, v in convert.items():
    print(f"    {k}: {v},")
print("}\n")

print("-=-=-=Mapa=-=-=-\n    [")
for linha in level_matrix[1:]:
    print("        [", end="")
    for tile in linha[:-1]:
        print(f"{convert[tuple(tile)]}, ", end="")
    print(f"{convert[tuple(linha[-1])]}],")
print("    ]")

