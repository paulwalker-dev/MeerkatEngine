#pragma once
#include "EngineCore.h"

typedef struct {
    int x, y;
    int n;
} TileComponent;

void *cd_tile_create();
void cd_tile_destroy(void *cd);

Component *c_tile_create();
