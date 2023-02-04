#pragma once
#include "EngineCore.h"

typedef struct {
    int vx, vy;
} VelocityComponent;

void *cd_velocity_create();

Component *c_velocity_create();
