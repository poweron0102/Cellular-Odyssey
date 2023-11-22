from main import *


class InGame(Game):
    scheduler: Scheduler
    events: Events
    parallax: Parallax
    dialogue_handler: DialogueHandler
    sprite_handler: SpriteHandler
    drawer: Drawer
    action: Actions
    ray_caster: RayCaster
    player: Player
    hud: Hud
    map: Map
