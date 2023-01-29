#include "Graphics.h"
#include "EngineCore.h"
#include "EngineMantle.h"
#include <unistd.h>
#include "SDL2/SDL.h"

#include "Components/Window.h"
#include "Components/Image.h"
#include "Tasks/Image.h"

void t_blank_window(List *cd, List *e)
{
    TASK_CD(cd, GraphicsWindow, cd_window);

    SDL_FillRect(
        cd_window->surface,
        NULL,
        SDL_MapRGB(
            cd_window->surface->format,
            0xFF, 0xFF, 0xFF));
}

void t_window(List *cd, List *e)
{
    TASK_CD(cd, GraphicsWindow, cd_window);

    SDL_Event event;
    while (SDL_PollEvent(&event))
        if (event.type == SDL_QUIT)
            cd_window->open = 0;

    SDL_UpdateWindowSurface(cd_window->window);
}

void graphics_create(Box *b)
{
    box_component(b, c_graphics_window_create);
    box_component(b, c_graphics_image_create);
    box_archetype(b, "GraphicsData",
                  "GraphicsWindow", 0);
    box_entity(b, "GraphicsData");
    box_task(b, t_blank_window, "GraphicsWindow", 0);
    box_task(b, t_image_update, "GraphicsImage", 0);
    box_task(b, t_window, "GraphicsWindow", 0);
}

#ifdef WEB
void graphics_loop_func(void *o) {
    Box *b;
    b = o;

    TASK_E(b->s->entities, GraphicsData, e);
    TASK_CD(e->data, GraphicsWindow, cd_window);

    if (!cd_window->open)
        emscripten_cancel_main_loop();

    box_update(b);
}
#endif

void graphics_loop(Box *b)
{
#ifndef WEB
    TASK_E(b->s->entities, GraphicsData, e);
    TASK_CD(e->data, GraphicsWindow, cd_window);

    while (cd_window->open) {
        box_update(b);
        SDL_Delay(100);
    }
#else
    emscripten_set_main_loop_arg(graphics_loop_func, b, 60, 1);
#endif
}

void graphics_destroy(Box *b)
{}
