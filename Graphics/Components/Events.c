#include "Events.h"
#include <stdlib.h>
#include "SDL2/SDL.h"

void *cd_graphics_events_create()
{
    CD_INIT(GraphicsEvents, cd);
    cd->events = list_create();
    return cd;
}

void cd_graphics_events_destroy(void *_cd)
{
    GraphicsEventsComponent *cd;
    cd = _cd;
    list_destroy(cd->events);
    free(cd);
}

Component *c_graphics_events_create()
COMPONENT3(GraphicsEvents,
           cd_graphics_events_create,
           cd_graphics_events_destroy);
