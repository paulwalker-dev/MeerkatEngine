#pragma once
#include "EngineMantle.h"

void graphics_create(Box *b);

#ifdef WEB
#include "emscripten.h"
void graphics_loop_func(void *b);
#endif

void graphics_loop(Box *b);

void graphics_destroy(Box *b);
