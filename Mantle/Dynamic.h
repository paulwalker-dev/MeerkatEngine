#pragma once
#include "EngineCore.h"

typedef struct {
    List *components;
    List *data;
} Dynamic;

typedef Dynamic DynamicComponent;

/**
 * Create a dynamic
 */
Dynamic *dynamic_create();

/**
 * Destroy dynamic
 */
void dynamic_destroy(Dynamic *d);

/**
 * Add a component to a dynamic
 */
void dynamic_append(Dynamic *d, Component *c);

/**
 * Remove a component on a dynamic by name
 */
void dynamic_drop(Dynamic *d, char *name);

Component *c_dynamic_create();
