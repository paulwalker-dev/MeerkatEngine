#pragma once
#include "EngineCore.h"
#include "SDL2/SDL.h"

typedef struct {
    int x;
    int y;
} GraphicsPositionComponent;

void *cd_graphics_position_create();

Component *c_graphics_position_create();
