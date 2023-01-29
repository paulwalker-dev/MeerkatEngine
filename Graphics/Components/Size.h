#pragma once
#include "EngineCore.h"
#include "SDL2/SDL.h"

typedef struct {
    int width;
    int height;
} GraphicsSizeComponent;

void *cd_graphics_size_create();

Component *c_graphics_size_create();
