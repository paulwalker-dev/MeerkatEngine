#pragma once
#include "Archetype.h"
#include "Component.h"
#include "lib/List.h"

/**
 */
typedef struct {
    int id;
    Archetype *archetype;
    List *data;
} Entity;

/**
 * Creates an entity
 */
Entity *entity_create(Archetype *a);

/**
 * Destroy an entity
 * @attention Archetype will stay allocated
 */
void entity_destroy(Entity *e);

/**
 * Destroy an entity, using void pointer
 * @attention This function should **ONLY** be used when absolutely necessary
 * @param e The pointer to the entity to deallocate
 */
void entity_cleanup(void *e);
