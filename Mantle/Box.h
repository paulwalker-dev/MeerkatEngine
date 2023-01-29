#pragma once
#include "EngineCore.h"

typedef struct {
    Store *s;
} Box;

/**
 * Create a container
 */
Box *box_create();

/**
 * Destroy a box
 */
void box_destroy(Box *b);

/**
 * Run updates on contained entities
 */
void box_update(Box *b);

/**
 * Wrapper function for component initialization
 */
void box_component(Box *b, Component *(* init_c)());

/**
 * Used in box_archetype wrapper
 * @attention This is an internal function, don't use it
 */
Archetype *_box_archetype_create(List *c);

/**
 * Makes archetype initialization less tedious
 * @param name Name of archetype
 * @param[in] ... List of components
 */
void box_archetype(Box *b, char *name, char *component, ...);

/**
 * Used in box_entity wrapper
 * @attention This is an internal function, don't use it
 */
Entity *_box_entity_create(List *a);

/**
 * Makes entity initialization less tedious
 * @param archetype Name of the parent archetype
 */
Entity *box_entity(Box *b, char *archetype);

/**
 * Used in box_task wrapper
 * @attention This is an internal function, don't use it
 */
void _box_task_placeholder(List *cd, List *e);

/**
 * Used in box_task wrapper
 * @attention This is an internal function, don't use it
 */
Task *_box_task_create(List *c);

/**
 * Makes task initialization less tedious
 * @param run Task runner script
 * @attention End component list with NULL
 * @param component List of components
 */
void box_task(Box *b, void (* run)(List *cd, List *e), char *component, ...);
