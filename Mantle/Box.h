#pragma once
#include "EngineCore.h"
#include "Task.h"

typedef struct {
    Store *s;
    List *tasks;
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
 * Makes archetype initialization less tedious
 * @param name Name of archetype
 * @param component List of components
 */
void box_archetype(Box *b, char *name, char *component, ...);

/**
 * Makes entity initialization less tedious
 * @param archetype Name of the parent archetype
 */
Entity *box_entity(Box *b, char *archetype);

/**
 * Makes task initialization less tedious
 * @param run Task runner script
 * @attention End component list with NULL
 * @param component List of components
 */
void box_task(Box *b, TASK_POINTER, char *component, ...);
