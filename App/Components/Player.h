#pragma once
#include "EngineCore.h"

#define PLAYER_NONE ""
#define PLAYER_SOLID "Solid"
#define PLAYER_LIQUID "Liquid"

extern char *player_states[];

typedef struct {
    char *state;
    char *old_state;
    int next;
} PlayerComponent;

void *cd_player_create();

Component *c_player_create();
