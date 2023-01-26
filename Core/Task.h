#pragma once
#include "Component.h"

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
