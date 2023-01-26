#pragma once
#include "lib/List.h"

typedef struct {
    char *name;
    void *data;
} ComponentData;

typedef struct {
    char *name;
    void *(* data_init)();
    void (* data_destroy)(void *cd);
} Component;

void *default_cd_create();

void default_cd_destroy(void *cd);

/**
 * Create component
 * @param Name of new component
 */
Component *component_create(char *name);

/**
 * Destroy Component
 */
void component_destroy(Component *a);

/**
 * Destroy an component, using void pointer
 * @attention This function should **ONLY** be used when absolutely necessary
 * @param e The pointer to the component to deallocate
 */
void component_cleanup(void *c);

/**
 * Find a component in a given list via name
 */
Component *component_find(List *l, char *name);

/**
 * Create component data for component
 */
ComponentData *component_data_create(Component *c);

/**
 * Destroy component data
 * @param data Data to deallocate
 */
void component_data_destroy(Component *c, ComponentData *cd);
