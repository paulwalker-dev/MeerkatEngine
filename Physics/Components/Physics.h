#pragma once
#include "EngineCore.h"

typedef struct {
    int id;
    int stationary;
    int floored;
} PhysicsComponent;

void *cd_physics_create();

Component *c_physics_create();
