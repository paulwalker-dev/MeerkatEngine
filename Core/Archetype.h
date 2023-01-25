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

/**
 * Finds component via name in given archetype
 * @param name The name of the component
 * @returns If not null, a pointer to the component
 */
Component *archetype_get(Archetype *a, char *name);
