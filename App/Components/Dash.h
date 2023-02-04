#pragma once
#include "EngineCore.h"

typedef struct {
    int enabled;
} DashComponent;

void *cd_dash_create();

Component *c_dash_create();
