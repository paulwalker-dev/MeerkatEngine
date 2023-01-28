#pragma once
#include "Component.h"
#include "lib/List.h"

typedef struct {
    char *name;
    List *components;
} Archetype;

/**
 * Create an archetype
 * @param name Name of the new archetype
 */
Archetype *archetype_create(char *name);

/**
 * Destroy an archetype
 */
void archetype_destroy(Archetype *a);

/**
 * Destroy an archetype, using void pointer
 * @attention This function should **ONLY** be used when absolutely necessary
 * @param e The pointer to the archetype to deallocate
 */
void archetype_cleanup(void *a);

/**
 * Find a archetype in a given list via name
 */
Archetype *archetype_find(List *l, char *name);

/**
 * Add a component to an archetype
 * @param c Component to add
 */
void archetype_append(Archetype *a, Component *c);

/**
 * Finds component via name in given archetype
 * @param name The name of the component
 * @returns If not null, a pointer to the component
 */
Component *archetype_get(Archetype *a, char *name);
