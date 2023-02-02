#pragma once
#include "EngineCore.h"

typedef struct {
    int x, y;
    int rotation;
} GraphicsPositionComponent;

void *cd_graphics_position_create();

Component *c_graphics_position_create();
