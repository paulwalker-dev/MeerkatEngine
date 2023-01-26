#pragma once
#include "Component.h"

typedef struct {
    List *components;
    void (* run)(List *cd);
} System;

/**
 * Create system
 * @param run Pointer to function to run every update
 */
System *system_create(void (* run)(List *cd));

/**
 * Add component to system requirements
 */
void system_component(System *s);
