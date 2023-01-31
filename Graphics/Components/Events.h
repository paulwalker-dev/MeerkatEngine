#pragma once
#include "EngineCore.h"

typedef struct {
    List *events;
} GraphicsEventsComponent;

void *cd_graphics_events_create();
void cd_graphics_events_destroy(void *cd);

Component *c_graphics_events_create();
