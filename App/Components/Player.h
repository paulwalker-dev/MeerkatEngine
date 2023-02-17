#pragma once
#include "EngineCore.h"

typedef struct {
    char *state;
    char *old_state;
} PlayerComponent;

void *cd_player_create();

Component *c_player_create();
