#pragma once
#include "EngineCore.h"

/**
 * Gets all component data off an entity, includes dynamic components if present
 * @attention Use list_free() for deallocation after use
 */
List *entity_data_get(Entity *e);

/**
 * Create a list of components by name
 * @attention You should use list_free() for deallocating
 * @param s Store containing the components
 * @param component Name of components
 */
List *component_list_create(Store *s, char *component, ...);
