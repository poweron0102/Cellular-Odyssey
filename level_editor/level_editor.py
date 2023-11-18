import pygame as pg
import numpy as np
import os

pg.init()
screen = pg.display.set_mode((800, 600))

# level_img = pg.image.load("levels_png/new_level.png").convert()
# level_matrix = pg.surfarray.pixels3d(level_img)

for dir_name in os.listdir("levels_png"):
    if not os.path.isdir(f'levels_png/{dir_name}'):
        continue

    with open(f'levels_png/{dir_name}/output.py', 'w') as file:
        file.write(f"world_map = np.array([\n   [\n")

        for file_name in ['walls.png', 'floor.png', 'ceiling.png']:
            level_img = pg.image.load(f"levels_png/{dir_name}/{file_name}").convert()
            level_matrix = pg.surfarray.pixels3d(level_img)

            convert: dict[np.array, int] = {}
            for index, color in enumerate(level_matrix[0]):
                color = tuple(color)
                if color in convert.keys():
                    break
                convert[color] = index

            print(f'\nlevels_png/{dir_name}/{file_name}')
            print("convert = {")
            for k, v in convert.items():
                print(f"    {k}: {v},")
            print("}\n")

            for linha in level_matrix[1:]:
                file.write("        [")
                for tile in linha[:-1]:
                    file.write(f"{convert[tuple(tile)]}, ")
                file.write(f"{convert[tuple(linha[-1])]}],\n")
            file.write("    ],\n    [\n" if file_name != 'ceiling.png' else "    ]\n")

        file.write("])\n")

exit()

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


with open('output.txt', 'w') as file:
    file.write("convert = {\n")
    for k, v in convert.items():
        file.write(f"    {k}: {v},\n")
    file.write("}\n\n")

    file.write("-=-=-=Mapa=-=-=-\n    [\n")
    for linha in level_matrix[1:]:
        file.write("        [")
        for tile in linha[:-1]:
            file.write(f"{convert[tuple(tile)]}, ")
        file.write(f"{convert[tuple(linha[-1])]}],\n")
    file.write("    ],\n")

