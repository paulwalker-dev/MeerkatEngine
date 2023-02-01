#include "Graphics.h"
#include "EngineMantle.h"
#include <unistd.h>
#include "SDL2/SDL.h"

#include "Components/Events.h"
#include "Components/Image.h"
#include "Components/Position.h"
#include "Components/Size.h"
#include "Components/Window.h"

#include "Tasks/Events.h"
#include "Tasks/Image.h"

void t_blank_window(Store *s, List *cd, List *e)
{
    TASK_CD(cd, GraphicsWindow, cd_window);
    SDL_SetRenderDrawColor(
        cd_window->renderer,
        0x00, 0x00, 0x00, 0xFF
    );
    SDL_RenderClear(cd_window->renderer);
}

void t_render(Store *s, List *cd, List *e)
{
    TASK_CD(cd, GraphicsWindow, cd_window);
    SDL_RenderPresent(cd_window->renderer);
}

void graphics_create(Box *b)
{
    box_component(b, c_graphics_events_create);
    box_component(b, c_graphics_image_create);
    box_component(b, c_graphics_position_create);
    box_component(b, c_graphics_size_create);
    box_component(b, c_graphics_window_create);

    box_archetype(b, "GraphicsData",
                  "GraphicsWindow",
                  "GraphicsEvents", NULL);
    box_entity(b, "GraphicsData");

    box_task(b, t_blank_window, "GraphicsWindow", NULL);
    box_task(b, t_get_events, "GraphicsEvents", NULL);
    box_task(b, t_event_quit, "GraphicsEvents", NULL);
    box_task(b, t_draw_image, "GraphicsImage", "GraphicsPosition", "GraphicsSize", NULL);
    box_task(b, t_render, "GraphicsWindow", NULL);
}

void graphics_loop(Box *b)
{
    TASK_E(b->s->entities, GraphicsData, e);
    TASK_CD(e->data, GraphicsWindow, cd_window);

    int fps;

    int start_time, end_time;
    int delay;
    float frame_time;

    fps = 60;
    frame_time = ((1.0f / fps) * 1000.0f);

    while (cd_window->open) {
        start_time = SDL_GetTicks();
        box_update(b);
        end_time = SDL_GetTicks();

        delay = frame_time - (end_time - start_time);
        if (delay > 0)
            SDL_Delay(delay);
    }
}

void graphics_destroy(Box *b)
{}
