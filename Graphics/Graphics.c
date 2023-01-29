#include "Graphics.h"
#include "EngineCore.h"
#include "EngineMantle.h"
#include <unistd.h>
#include "SDL2/SDL.h"

#include "Components/Image.h"
#include "Components/Position.h"
#include "Components/Size.h"
#include "Components/Window.h"
#include "Tasks/Image.h"

void t_blank_window(List *cd, List *e)
{
    TASK_CD(cd, GraphicsWindow, cd_window);
    SDL_SetRenderDrawColor(
        cd_window->renderer,
        0x00, 0x00, 0x00, 0xFF
    );
    SDL_RenderClear(cd_window->renderer);
}

void t_window(List *cd, List *e)
{
    TASK_CD(cd, GraphicsWindow, cd_window);

    SDL_Event event;
    while (SDL_PollEvent(&event))
        if (event.type == SDL_QUIT)
            cd_window->open = 0;

    SDL_RenderPresent(cd_window->renderer);
}

void graphics_create(Box *b)
{
    box_component(b, c_graphics_image_create);
    box_component(b, c_graphics_position_create);
    box_component(b, c_graphics_size_create);
    box_component(b, c_graphics_window_create);

    box_archetype(b, "GraphicsData",
                  "GraphicsWindow", 0);
    box_entity(b, "GraphicsData");

    box_task(b, t_blank_window, "GraphicsWindow", 0);
    box_task(b, t_draw_image, "GraphicsImage", "GraphicsPosition", "GraphicsSize", 0);
    box_task(b, t_window, "GraphicsWindow", 0);
}

#ifdef WEB
void graphics_loop_func(void *b) {
    box_update(b);
}
#endif

void graphics_loop(Box *b)
{
    int fps;
    fps = 60;

#ifndef WEB
    TASK_E(b->s->entities, GraphicsData, e);
    TASK_CD(e->data, GraphicsWindow, cd_window);

    int start_time, end_time;
    int delay;
    float frame_time;

    start_time = SDL_GetTicks();
    while (cd_window->open) {
        start_time = SDL_GetTicks();
        box_update(b);
        end_time = SDL_GetTicks();

        frame_time = (end_time - start_time) / 1.0f;
        delay = ((1.0f / fps) * 1000.0f) - (frame_time);

        if (delay > 0)
            SDL_Delay(delay);
    }
#else
    emscripten_set_main_loop_arg(graphics_loop_func, b, fps, 1);
#endif
}

void graphics_destroy(Box *b)
{}
