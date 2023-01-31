#pragma once
#include "EngineCore.h"

typedef struct {
    List *events;
} GraphicsEventsComponent;

void *cd_graphics_events_create();

Component *c_graphics_events_create();
