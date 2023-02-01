#pragma once
#include "Archetype.h"
#include "Component.h"
#include "Entity.h"
#include "lib/List.h"

typedef struct {
    List *components;
    List *archetypes;
    List *entities;
} Store;

/**
 * Create a store
 */
Store *store_create();

/**
 * Destroy a store
 * @attention This function will destroy all game data contained in the store
 */
void store_destroy(Store *store);

/**
 * Update data in entities using tasks
 */
void store_update(Store *s);

/**
 * Create component to store, created via function pointer
 * @param init_c Function to create component
 */
Component *store_component(Store *store, Component *(* init_c)());

/**
 * Create archetype to store, created via function pointer
 * @param init_a Function to create archetype
 */
Archetype *store_archetype(Store *store, Archetype *(* init_a)(List *c));

/**
 * Create entity to store, created via function pointer
 * @param init_e Function to create entity
 */
Entity *store_entity(Store *store, Entity *(* init_e)(List *a));
