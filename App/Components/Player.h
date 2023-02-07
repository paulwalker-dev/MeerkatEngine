#pragma once
#include "EngineCore.h"
#include "SDL2/SDL.h"

typedef struct {
    SDL_Keycode key;
    int pressed;
} PlayerKey;

typedef struct {
    PlayerKey up;
    PlayerKey down;
    PlayerKey left;
    PlayerKey right;
    PlayerKey reset;
    int jump_count;
} PlayerComponent;

void *cd_player_create();

Component *c_player_create();
