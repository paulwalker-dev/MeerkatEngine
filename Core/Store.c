#include "Store.h"
#include <stdlib.h>

Store *store_create()
{
    Store *s;

    s = malloc(sizeof(Store));
    s->components = list_create();
    s->tasks = list_create();
    s->archetypes = list_create();
    s->entities = list_create();

    return s;
}

void store_destroy(Store *s)
{
    list_cleanup(s->entities, entity_cleanup);
    list_cleanup(s->archetypes, archetype_cleanup);
    list_cleanup(s->tasks, task_cleanup);
    list_cleanup(s->components, component_cleanup);

    free(s);
}

void store_update(Store *s)
{
    int i;
    Task *t;

    for (i = 0; i < s->tasks->length; ++i) {
        t = list_get(s->tasks, i);
        task_run(t, s->entities);
    }
}

Component *store_component(Store *s, Component *(* init_c)())
{
    Component *c;

    c = init_c();
    list_append(s->components, c);
    return c;
}

Archetype *store_archetype(Store *s, Archetype *(* init_a)(List *c))
{
    Archetype *a;

    a = init_a(s->components);
    list_append(s->archetypes, a);
    return a;
}

Entity *store_entity(Store *s, Entity *(* init_e)(List *a))
{
    Entity *e;

    e = init_e(s->archetypes);
    list_append(s->entities, e);
    return e;
}

Task *store_task(Store *s, Task *(* init_t)(List *c))
{
    Task *t;

    t = init_t(s->components);
    list_append(s->tasks, t);
    return t;
}
