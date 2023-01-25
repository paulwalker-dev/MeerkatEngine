#pragma once
#include "Archetype.h"
#include "Component.h"
#include "Entity.h"
#include "lib/List.h"

typedef struct {
    List *Components;
    List *Archetypes;
    List *Entities;
} Store;

/**
 * Create a store
 */
Store *store_create();

/**
 * Destroy a store
 * @attention This function will destroy all game data contained in the store
 */
void store_destroy(Store *s);
