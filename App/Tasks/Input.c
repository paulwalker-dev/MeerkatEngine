#include "Input.h"
#include "EngineMantle.h"
#include "EngineGraphics.h"

#include "../Components/Input.h"

void check_keys(InputComponent *cd_input, SDL_Event event, int state)
{
    InputKey *key;
    int i;

    for (i = 0; i < cd_input->keys->length; ++i) {
        key = list_get(cd_input->keys, i);

        if (key->code == event.key.keysym.sym)
            key->state = state;
    }
}

void t_update_input(Store *s, List *cd, List *e)
{
    TASK_E(e, GraphicsData, e_window);
    TASK_CD(e_window->data, GraphicsEvents, cd_events);
    TASK_CD(cd, Input, cd_input);
    SDL_Event *event;
    InputKey *key;
    int i, j;


    for (i = 0; i < cd_events->events->length; ++i) {
        event = list_get(cd_events->events, i);
        if (event->type == SDL_KEYUP)
            check_keys(cd_input, *event, 0);
        if (event->type == SDL_KEYDOWN)
            check_keys(cd_input, *event, 1);
    }
}
