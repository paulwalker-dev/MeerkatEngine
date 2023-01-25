#include "Entity.h"
#include "lib/UniqueId.h"
#include "stdlib.h"

Entity *entity_create(Archetype *a)
{
    Entity *e;

    e = malloc(sizeof(Entity));
    e->id = generate_id();

    e->archetype = a;
    e->data = list_create();

    return e;
}

void entity_destroy(Entity *e)
{
    list_destroy(e->data);
    free(e);
}
