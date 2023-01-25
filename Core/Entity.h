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
void entity_destroy();
