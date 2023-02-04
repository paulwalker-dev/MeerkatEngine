#pragma once
#include "EngineCore.h"

typedef struct {
    int tile_width, tile_height;
    int width, height; /**< In tiles */
    List *filenames;
} GraphicsStitchComponent;

void *cd_graphics_stitch_create();

void cd_graphics_stitch_destroy(void *cd);

Component *c_graphics_stitch_create();
