#include "Window.h"
#include <stdlib.h>
#include "SDL2/SDL.h"

void *cd_graphics_window_create()
{
    CD_INIT(GraphicsWindow, cd);

    SDL_Window *window;
    SDL_Surface *surface;
    SDL_Renderer *renderer;

    cd->width = 680;
    cd->height = 480;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        panic("Graphics init failed");

    window = SDL_CreateWindow(
        "EngineApp",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        cd->width, cd->height, 0
    );

    if (!window)
        panic("Failed to create window");

    surface = SDL_GetWindowSurface(window);

    if (!surface)
        panic("Failed to get window surface");

    renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED
    );

    if (!renderer)
        panic("Failed to initialize renderer");

    SDL_RenderSetScale(renderer, 4, 4);

    cd->open = 1;
    cd->window = window;
    cd->surface = surface;
    cd->renderer = renderer;

    return cd;
}

void cd_graphics_window_destroy(void *_cd)
{
    GraphicsWindowComponent *cd = _cd;

    SDL_DestroyRenderer(cd->renderer);
    SDL_DestroyWindow(cd->window);
    SDL_Quit();
}

Component *c_graphics_window_create()
COMPONENT3(GraphicsWindow,
    cd_graphics_window_create,
    cd_graphics_window_destroy);
