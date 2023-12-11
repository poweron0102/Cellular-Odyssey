# Desc: Arquivo de configurações do jogo
# import pygame as pg

FastMath = True  # Gambiarra para ganhar speed
Parallel = True

RES = (1280, 720)
SCALE_RES = (RES[0]/1280, RES[1]/720)
#  ['800x600', '640x360', '1280x720', '1920x1080']
FULLSCREEN = False
VOLUME = 50.0
SCALE = 2

FPS = 60
Mouse_sens = 0.005

#Player_speed = 200
#Player_size = 4
#Posicao_inicial = (50, 50)
#Default_angulo = 0
#NumThreads = 2

Texture_Res = 128
Tile_size = 64

FOV = 60
Render_dist = 35
Sprite_Ren_dist = 2048

Mine_Map_zoom = 12
Mini_Map_position = (2 * Mine_Map_zoom, RES[1] - 29 * Mine_Map_zoom)

RenderWidth = RES[0]
HalfRenderWidth = RenderWidth // 2
RenderHeight = RES[1]
HalfRenderHeight = RenderHeight // 2
HalfFOV = FOV // 2

"""
RenderWidth = RES[0] // SCALE
HalfRenderWidth = RenderWidth // 2
RenderHeight = RES[1] // SCALE
HalfRenderHeight = RenderHeight // 2
HalfFOV = FOV // 2
"""
