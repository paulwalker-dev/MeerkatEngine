#pragma once
#include "EngineCore.h"

typedef struct {
    int enabled;
} FPSComponent;

void *cd_fps_create();

Component *c_fps_create();
