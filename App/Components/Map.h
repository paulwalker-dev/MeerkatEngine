#pragma once
#include "EngineCore.h"

typedef struct {
    int started;
} MapComponent;

void *cd_map_create();

Component *c_map_create();
