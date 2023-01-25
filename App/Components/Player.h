#pragma once
#include "EngineCore.h"

typedef struct {
    char *player_name;
} PlayerComponent;

void *cd_player_create();

Component *c_player_create();
