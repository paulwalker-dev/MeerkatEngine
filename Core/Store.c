#include "Store.h"
#include <stdarg.h>
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

Archetype *store_archetype(Store *s, char *name, char *component, ...)
{
    Archetype *a;
    Component *c;
    va_list ap;

    a = archetype_create(name);

    va_start(ap, component);
    while (component) {
        c = component_find(s->components, component);
        list_append(a->components, c);
        component = va_arg(ap, char *);
    }
    va_end(ap);

    list_append(s->archetypes, a);

    return a;
}

Entity *store_entity(Store *s, char *archetype)
{
    Archetype *a;
    Entity *e;

    a = archetype_find(s->archetypes, archetype);
    e = entity_create(a);
    list_append(s->entities, e);
    return e;
}
