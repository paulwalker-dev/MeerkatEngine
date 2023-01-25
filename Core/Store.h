#pragma once
#include "Archetype.h"
#include "Component.h"
#include "Entity.h"
#include "lib/List.h"

typedef struct {
    List *items;
} Store;

extern List *ArchetypeStore;
