#include "Events.h"
#include "EngineCore.h"
#include "SDL2/SDL.h"

#include "../Components/Events.h"
#include "../Components/Window.h"

void t_get_events(List *cd, List *e)
{
    TASK_CD(cd, GraphicsEvents, cd_events);

    list_destroy(cd_events->events);
    cd_events->events = list_create();

    SDL_Event event;
    SDL_Event *p_event;
    while (SDL_PollEvent(&event)) {
        p_event = malloc(sizeof(SDL_Event));
        memcpy(p_event, &event, sizeof(SDL_Event));
        list_append(cd_events->events, p_event);
    }
}

void t_event_quit(List *cd, List *e)
{
    TASK_E(e, GraphicsData, e_window);
    TASK_CD(e_window->data, GraphicsWindow, cd_window);
    TASK_CD(cd, GraphicsEvents, cd_events);
    SDL_Event *event;
    int i;

    for (i = 0; i < cd_events->events->length; ++i) {
        event = list_get(cd_events->events, i);
        if (event->type == SDL_QUIT)
            cd_window->open = 0;
    }
}
