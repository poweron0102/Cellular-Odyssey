import math
from numba import njit
from settings import *


@njit()
def angle_to_fist(angle: float) -> float:
    if angle > 2 * math.pi:
        angle -= 2 * math.pi
    if angle < 0:
        angle += 2 * math.pi
    return angle


@njit()
def distancia(ponto_A, ponto_B):
    return math.sqrt(((ponto_A[0] - ponto_B[0]) ** 2) + (ponto_A[1] - ponto_B[1]) ** 2)


@njit()
def to_map(x, y):
    return int(x * Tile_size), int(y * Tile_size)


@njit()
def sig(numero):
    if numero < 0:
        return -1
    else:
        return 1
