#pragma once
#include "Component.h"
#include "lib/List.h"

typedef struct {
    char *name;
    List *components;
} Archetype;

/**
 * Create an archetype
 */
Archetype *archetype_create();

/**
 * Destroy an archetype
 */
void archetype_destroy(Archetype *a);
