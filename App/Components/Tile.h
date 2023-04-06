#pragma once
#include "EngineCore.h"

typedef struct {
    int x, y;
    List *superposition;
} TileComponent;

void *cd_tile_create();
void cd_tile_destroy(void *cd);

Component *c_tile_create();
