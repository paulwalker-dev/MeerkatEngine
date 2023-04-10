#pragma once
#include "EngineCore.h"

#define WINDOW_WIDTH 680
#define WINDOW_HEIGHT 480

typedef struct {
    int should_close;
} WindowComponent;

void *cd_window_create();
void cd_window_destroy(void *cd);

Component *c_window_create();
