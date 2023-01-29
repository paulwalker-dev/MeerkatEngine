#include "Window.h"

void *cd_graphics_window_create()
{
    CD_INIT(GraphicsWindow, cd);

    SDL_Window *window;
    SDL_Surface *surface;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        panic("Graphics init failed");

    window = SDL_CreateWindow(
        "SDL2 Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        680, 480, 0
    );

    if (!window)
        panic("Failed to create window");

    surface = SDL_GetWindowSurface(window);

    if (!surface)
        panic("Failed to get window surface");

    SDL_FillRect(
        surface,
        NULL,
        SDL_MapRGB(
            surface->format,
            0xFF, 0xFF, 0xFF));

    SDL_UpdateWindowSurface(window);

    cd->open = 1;
    cd->window = window;
    cd->surface = surface;

    return cd;
}

void cd_graphics_window_destroy(void *_cd)
{
    GraphicsWindowComponent *cd = _cd;

    SDL_DestroyWindow(cd->window);
    SDL_Quit();
}

Component *c_graphics_window_create()
COMPONENT3(GraphicsWindow,
           cd_graphics_window_create,
           cd_graphics_window_destroy);
