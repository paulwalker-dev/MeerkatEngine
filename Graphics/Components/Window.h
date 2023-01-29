#pragma once
#include "EngineCore.h"
#include "SDL2/SDL.h"

typedef struct {
    int open;
    int width, height;
    SDL_Window *window;
    SDL_Surface *surface;
    SDL_Renderer *renderer;
} GraphicsWindowComponent;

void *cd_graphics_window_create();
void cd_graphics_window_destroy(void *cd);

Component *c_graphics_window_create();
