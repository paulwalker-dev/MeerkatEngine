#include "Player.h"
#include "EngineCore.h"
#include "SDL2/SDL.h"

PlayerKey player_key_init(SDL_Keycode keycode) {
    PlayerKey key;
    key.key = keycode;
    key.pressed = 0;
    return key;
}

void *cd_player_create()
{
    CD_INIT(Player, cd);
    cd->up    = player_key_init(SDLK_w);
    cd->down  = player_key_init(SDLK_s);
    cd->left  = player_key_init(SDLK_a);
    cd->right = player_key_init(SDLK_d);
    cd->reset = player_key_init(SDLK_r);
    return cd;
}

Component *c_player_create()
COMPONENT(Player, cd_player_create);
