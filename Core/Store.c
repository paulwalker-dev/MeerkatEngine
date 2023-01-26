#include "Store.h"
#include <stdlib.h>

Store *store_create()
{
    Store *store;

    store = malloc(sizeof(Store));
    store->components = list_create();
    store->archetypes = list_create();
    store->entities = list_create();

    return store;
}

void store_destroy(Store *store)
{
    list_cleanup(store->entities, entity_cleanup);
    list_cleanup(store->archetypes, archetype_cleanup);
    list_cleanup(store->components, component_cleanup);

    free(store);
}

Component *store_component(Store *store, Component *(* init_c)())
{
    Component *c;

    c = init_c();
    list_append(store->components, c);
    return c;
}

Archetype *store_archetype(Store *store, Archetype *(* init_a)())
{
    Archetype *a;

    a = init_a();
    list_append(store->archetypes, a);
    return a;
}

Entity *store_entity(Store *store, Entity *(* init_e)())
{
    Entity *e;

    e = init_e();
    list_append(store->entities, e);
    return e;
}
