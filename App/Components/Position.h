#pragma once
#include "EngineCore.h"
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} PositionComponent;

void *cd_position_create();

Component *c_position_create();
