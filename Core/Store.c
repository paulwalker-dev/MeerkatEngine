#include "Store.h"
#include <stdlib.h>

Store *store_create()
{
    Store *s;

    s = malloc(sizeof(Store));
    s->components = list_create();
    s->archetypes = list_create();
    s->entities = list_create();

    return s;
}

void store_destroy(Store *s)
{
    list_cleanup(s->entities, entity_cleanup);
    list_cleanup(s->archetypes, archetype_cleanup);
    list_cleanup(s->components, component_cleanup);

    free(s);
}

Component *store_component(Store *s, Component *(* init_c)())
{
    Component *c;

    c = init_c();
    list_append(s->components, c);

    return c;
}

Archetype *store_archetype(Store *s, Archetype *(* init_a)());

Entity *store_entity(Store *s, Entity *(* init_e)());
