#include "Box.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

Box *box_create()
{
    Box *b;

    b = malloc(sizeof(Box));
    b->s = store_create();
    return b;
}

void box_destroy(Box *b)
{
    store_destroy(b->s);
    free(b);
}

void box_update(Box *b)
{
    store_update(b->s);
}

void box_component(Box *b, Component *(* init_c)())
{
    store_component(b->s, init_c);
}

Archetype *_box_archetype_create(List *c)
{
    Archetype *a;
    a = archetype_create("BOX_PLACEHOLDER");
    return a;
}

void box_archetype(Box *b, char *name, char *component, ...)
{
    Archetype *a;
    Component *c;
    va_list ap;
    char *cname;

    a = store_archetype(b->s, _box_archetype_create);
    a->name = name;

    va_start(ap, component);
    for (; component; component = va_arg(ap, char *)) {
        c = component_find(b->s->components, component);
        list_append(a->components, c);
    }
    va_end(ap);
}

Entity *_box_entity_create(List *l)
{
    Archetype *a;
    Entity *e;

    a = list_pop(l, l->length-1);
    e = entity_create(a);
    return e;
}

Entity *box_entity(Box *b, char *archetype)
{
    Archetype *a;
    Entity *e;

    // FIXME: This is a hack, might break in the future
    a = archetype_find(b->s->archetypes, archetype);
    list_append(b->s->archetypes, a);
    e = store_entity(b->s, _box_entity_create);
    return e;
}

void _box_task_placeholder(List *cd, List *e)
{
    panic("Task initialized with box wrapper in invalid state");
}

Task *_box_task_create(List *c)
{
    Task *t;

    t = task_create(_box_task_placeholder);
    return t;
}

void box_task(Box *b, void (* run)(List *cd, List *e), char *component, ...)
{
    Task *t;
    Component *c;
    va_list ap;

    t = store_task(b->s, _box_task_create);
    t->run = run;

    va_start(ap, component);
    for (; component; component = va_arg(ap, char *)) {
        c = component_find(b->s->components, component);
        task_append(t, c);
    }
    va_end(ap);
}
