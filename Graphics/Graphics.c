#include "Graphics.h"
#include "EngineCore.h"
#include "EngineMantle.h"
#include "SDL2/SDL.h"

void t_window_run(List *l)
{
    TASK_CD(l, GraphicsWindow, cd_window);

    SDL_Event e;
    while (SDL_PollEvent(&e))
        if (e.type == SDL_QUIT)
            cd_window->open = 0;
}


void graphics_create(Box *b)
{
    box_component(b, c_graphics_window_create);
    box_archetype(b, "GraphicsData",
                  "GraphicsWindow", 0);
    box_entity(b, "GraphicsData");
    box_task(b, t_window_run, "GraphicsWindow", 0);
}

void graphics_loop(Box *b)
{
    // TODO: Make a helper function
    Archetype *a;
    Entity *e;

    a = archetype_find(
        b->s->archetypes,
        "GraphicsData"
    );
    if (!a)
        error:
        panic("Graphics api not initialized properly");

    e = entity_find(b->s->entities, a);
    if (!e)
        goto error;

    TASK_CD(e->data, GraphicsWindow, cd_window);

    while (cd_window->open) {
        box_update(b);
    }
}

void graphics_destroy(Box *b)
{}
