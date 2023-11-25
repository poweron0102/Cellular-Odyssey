#
# This is the base file for all organs. It contains the base functions for all organs maps.
#
from main import *

TileSet = [
    Tile(False, False, [255, 255, 255], 0),
    Tile(True, True, 'blue', 1),
    Tile(True, True, 'blue', 2),
    Tile(True, True, 'blue', 3),
    Tile(True, True, 'blue', 4),
    Tile(True, True, 'blue', 5),
    Tile(True, True, 'blue', 7),
    Tile(True, True, 'blue', 8),
    Tile(False, False, 'green', 0),  # add action
    Tile(False, False, 'red', 0),  # add action
    Tile(False, True, 'black', 9),  # door L
    Tile(False, True, 'black', 10),  # door R
    Tile(True, True, 'blue', 11),
    Tile(True, True, 'blue', 12),
]

TextureSet = [
    None,
    Texture('p_1'),
    Texture('p_3'),
    Texture('p_8'),
    Texture('p_6'),
    Texture('p_13'),
    Texture('p_5'),
    Texture('p_2'),
    Texture('wall'),
    Texture('wallP2R wallP2R wallP2R wallP2R'),
    Texture('wallP2L wallP2L wallP2L wallP2L'),
]
AnimatedTextureSet = [
    AnimatedTexture(['wallX1', 'wallX2'], 1),
    AnimatedTexture(['wallV1', 'wallV2'], 1),
]
TextureSet.extend(AnimatedTextureSet)

TextureFloor = [
    'cobblestone',
    'grass_block_top',
    'chiseled_stone_bricks',
    'birch_planks',
    'tetoh0',
    # 'tetoh1',
    'tetoh2',
    'tetov0',
    # 'tetov1',
    'tetov2',
]

world_map = np.array([
    [
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 13, 8, 8, 13, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 2, 6, 5, 4, 5, 3, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 3, 5, 4, 5, 6, 2, 0, 0],
        [0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0],
        [0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0],
        [0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0],
        [10, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 11],
        [11, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 10],
        [0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0],
        [0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0],
        [0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0],
        [0, 0, 2, 6, 5, 4, 5, 3, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 3, 5, 4, 5, 6, 2, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 13, 8, 8, 13, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    ],
    [
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 1, 1, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 1, 1, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 1, 1, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 1, 1, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 1, 1, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 1, 1, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 1, 1, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 1, 1, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 3, 1, 1, 3, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 0, 0],
        [0, 0, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 3, 1, 1, 3, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 0, 0],
        [0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0],
        [0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0],
        [0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0],
        [0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0],
        [0, 0, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 3, 1, 1, 3, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 0, 0],
        [0, 0, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 3, 1, 1, 3, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 1, 1, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 1, 1, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 1, 1, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 1, 1, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 1, 1, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 1, 1, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 1, 1, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 3, 1, 1, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    ],
    [
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0],
        [0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    ]
])


def init(in_game: 'InGame', player_type: PlayerType):
    in_game.scheduler = Scheduler(in_game)
    in_game.map = Map(in_game, world_map, TileSet, TextureSet, TextureFloor)
    in_game.player = Player(in_game, *to_map(14, 26.3), 180, player_type)
    in_game.ray_caster = RayCaster(in_game)
    in_game.action = Actions(in_game)
    in_game.drawer = Drawer(in_game)
    in_game.dialogue_handler = DialogueHandler(in_game)
    in_game.parallax = Parallax(None, "ceu", in_game)
    in_game.sprite_handler = SpriteHandler(in_game)
    in_game.hud = Hud(in_game)

    """
    evt = Event(in_game)
    evt.add([
        (evt.MK_dig, Dialogue(
            7,
            "Oh, i'm really sorry. but we are doing some construction.",
            "platelet",
            audio='construcao'
        )),
        (evt.MK_dig, Dialogue(
            2,
            "No way we can snappy by?",
            "ae3803pla",
            audio='jeitodepassar'
        )),
        (evt.MK_dig, Dialogue(
            10,
            "No way at all. You see, what happened was there as a bit of trouble so construction get delayed.\
             I gest the delivery people had made a big mistake.",
            "platelet",
            audio='dellead'
        )),
        (evt.setattr, None, 'action', evt.run),
        (evt.restart, False),
    ])
    in_game.sprite_handler.add(Sprite(in_game, 'platelet', *to_map(10.5, 11.5), action=evt.run))
    """

    routes = [
        [to_map(13.5, 26), to_map(12.5, 25.5), to_map(12.5, 15.5), to_map(7.5, 15.5), to_map(7.5, 17)],
        [to_map(13.5, 26), to_map(12.5, 25.5), to_map(12.5, 15.5), to_map(4.5, 15.5), to_map(4.5, 17)],
        [to_map(14.5, 26), to_map(15.5, 25.5), to_map(15.5, 15.5), to_map(20.5, 15.5), to_map(20.5, 17)],
        [to_map(14.5, 26), to_map(15.5, 25.5), to_map(15.5, 15.5), to_map(23.5, 15.5), to_map(23.5, 17)],
    ]
    for index, route in enumerate(routes):
        evt = Event(in_game)
        evt.add([
            (evt.IF, lambda: not in_game.player.enable_input),
            (evt.restart, False),
            (evt.setattr, None, 'walking', False),
            (evt.MK_dig, Dialogue(
                2,
                'It is a beautiful day, isn\'t it?',
                'ordcell',
            )),
            (evt.setattr, None, 'walking', True),
            (evt.setattr, None, 'action', evt.run),
            (evt.restart, False),
        ])
        in_game.scheduler.add(
            index * 8,
            in_game.sprite_handler.add,
            ordcell := MovingSprite(
                in_game, 'ordinary-cell', 0, 0, scale=0.55, shift=0.3,
                route=route
            )
        )
        ordcell.action = evt.run

    in_game.sprite_handler.add(Sprite(in_game, 'tree', *to_map(11, 11), scale=1.6, shift=1.2))
    in_game.sprite_handler.add(Sprite(in_game, 'tree', *to_map(17, 11), scale=1.6, shift=1.2))
    in_game.sprite_handler.add(Sprite(in_game, 'tree', *to_map(11, 17), scale=1.6, shift=1.2))
    in_game.sprite_handler.add(Sprite(in_game, 'tree', *to_map(17, 17), scale=1.6, shift=1.2))


    """
    evt = Event(in_game)
    evt.add([
        (evt.sleep, 1),
        (evt.MK_move, in_game.player, *to_map(14, 26.2)),
        (evt.sleep, 1),
        (evt.MK_dig, Dialogue(
            2,
            'Ah, i cant get lost again, i need to find the way to the lungs.',
            'AE3803',
        )),
        (evt.MK_dig, Dialogue(
            2,
            'I think i find it, it should be this way.',
            'AE3803',
        )),
        (evt.MK_move, in_game.player, *to_map(14, 23.5)),
        (evt.MK_look_at, math.radians(90)),
        (evt.setattr, in_game.player, 'enable_input', True),
        (evt.wait, lambda: in_game.player.x <= 18 * Tile_size),
        (evt.MK_dig, Dialogue(
            2,
            'What is this? A Pneumococos? Ah!!!!',
            'AE3803',
        )),
    ], True)
    """


def loop(in_game: 'InGame'):
    for animated in AnimatedTextureSet:
        animated.update(in_game.delta_time)

    in_game.scheduler.update()
    in_game.player.update()
    in_game.action.update()
    in_game.parallax.update()
    in_game.ray_caster.update()
    in_game.dialogue_handler.update()
    in_game.sprite_handler.update()

    in_game.drawer.update()
    in_game.hud.update()
