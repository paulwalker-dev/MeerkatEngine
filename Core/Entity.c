#include "Entity.h"
#include "lib/UniqueId.h"
#include "lib/Panic.h"
#include <stdlib.h>

Entity *entity_create(Archetype *a)
{
    int i;
    Component *c;
    Entity *e;
    List *components;

    e = malloc(sizeof(Entity));
    e->id = generate_id();

    e->archetype = a;
    e->data = list_create();

    // Allocate data for entity
    i = 0;
    components = e->archetype->components;
    while ((c = list_get(components, i++)) != NULL) {
        list_append(components, component_data_create(c));
    }

    return e;
}

void entity_destroy(Entity *e)
{
    ComponentData *cd;
    Component *c;

    while (e->data->length) {
        cd = list_pop(e->data, 0);
        c = archetype_get(e->archetype, cd->name);

        // It's possible for a component to be removed from an archetype after use.
        // When this happens it is impossible to deallocate component data.
        if (c == NULL)
            panic("(Core/Entity.c) Entity in inconsistent state while deallocating");

        component_data_destroy(c, cd);
    }
    list_destroy(e->data);
    free(e);
}

void entity_cleanup(void *e)
{
    entity_destroy(e);
}
