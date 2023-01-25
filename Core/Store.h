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
void store_destroy(Store *s);

/**
 * Add component to store, created via function pointer
 * @param init_c Function to create component
 */
Component *store_component(Store *s, Component *(* init_c)());

/**
 * Add archetype to store, created via function pointer
 * @param init_a Function to create archetype
 */
Archetype *store_archetype(Store *s, Archetype *(* init_a)());

/**
 * Add entity to store, created via function pointer
 * @param init_e Function to create entity
 */
Entity *store_entity(Store *s, Entity *(* init_e)());
