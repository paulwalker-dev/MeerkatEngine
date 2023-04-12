#pragma once
#include "EngineCore.h"

/**
 * Gets all component data off an entity, includes dynamic components if present
 * @attention Use list_free() for deallocation after use
 */
List *entity_data_get(Entity *e);
