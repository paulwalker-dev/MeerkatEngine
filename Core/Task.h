#pragma once
#include "Archetype.h"
#include "Component.h"

#define TASK_CD(name, var) _TASK_CD(name, var, _ ## var)
#define _TASK_CD(name, var, tmp) ComponentData* tmp; \
    name ## Component * var; \
    tmp = component_data_find(l, # name); \
    var = tmp -> data;


typedef struct {
    List *components;
    void (* run)(List *cd);
} Task;

/**
 * Create task
 * @param run Pointer to function to run every update
 */
Task *task_create(void (* run)(List *cd));

/**
 * Destroy Task
 */
void task_destroy(Task *t);

/**
 * Destroy a task, using void pointer
 * @attention This function should **ONLY** be used when absolutely necessary
 * @param e The pointer to the task to deallocate
 */
void task_cleanup(void *t);

/**
 * Add a component to a task
 * @param c Component to add to requirements
 */
void task_append(Task *t, Component *c);

/**
 * Check if given archetype contains certain components
 * @param c List of components to check for
 * @returns Zero if archetype contains specified components
 */
int task_filter(Archetype *a, List *c);

/**
 * Run a task
 * @param l List of entities the task is allowed to modify
 */
void task_run(Task *t, List *l);
