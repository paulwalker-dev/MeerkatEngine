#pragma once
#include "EngineCore.h"
#include "SDL2/SDL.h"

typedef struct {
    char *name;
    int state;
    SDL_Keycode code;
} InputKey;

typedef struct {
    List *keys;
} InputComponent;

int input_key_status(InputComponent *i, char *name);

void *cd_input_create();

void cd_input_destroy(void *cd);

Component *c_input_create();
