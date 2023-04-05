#pragma once
#include "EngineCore.h"

typedef struct {
    int x, y;
} PositionComponent;

void *cd_position_create();

Component *c_position_create();
