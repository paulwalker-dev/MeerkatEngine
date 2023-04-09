#pragma once
#include "EngineCore.h"

typedef struct {
} WindowComponent;

void *cd_window_create();
void cd_window_destroy(void *cd);

Component *c_window_create();
