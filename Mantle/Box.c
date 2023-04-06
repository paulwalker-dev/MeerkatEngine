#include "Box.h"
#include <stdarg.h>
#include <stdlib.h>

#include "Dynamic.h"

Box *box_create()
{
    Box *b;

    b = malloc(sizeof(Box));
    b->s = store_create();
    b->tasks = list_create();

    box_component(b, c_dynamic_create);

    return b;
}

void box_destroy(Box *b)
{
    list_cleanup(b->tasks, task_cleanup);
    store_destroy(b->s);
    free(b);
}

void box_update(Box *b)
{
    Task *t;
    int i, j;

    for (i = 0; i < 10; ++i) {
        for (j = 0; j < b->tasks->length; ++j) {
            t = list_get(b->tasks, j);
            if (t->priority != i) continue;
            task_run(b->s, t, b->s->entities);
        }
    }
}

void box_component(Box *b, Component *(* init_c)())
{
    store_component(b->s, init_c);
}

void box_archetype(Box *b, char *name, char *component, ...)
{
    Archetype *a;
    Component *c;
    va_list ap;

    /* You cannot pass va_args in C */
    a = store_archetype(b->s, name, NULL);

    /* Workaround */
    va_start(ap, component);
    while (component) {
        c = component_find(b->s->components, component);
        list_append(a->components, c);
        component = va_arg(ap, char *);
    }
    va_end(ap);
}

Entity *box_entity(Box *b, char *archetype)
{
    Entity *e;
    e = store_entity(b->s, archetype);
    return e;
}

void box_priority(Box *b, int priority)
{
    b->task_priority = priority;
}


void box_task(Box *b, TASK_POINTER, char *component, ...)
{
    Task *t;
    Component *c;
    va_list ap;

    t = task_create(run);
    t->priority = b->task_priority;
    list_append(b->tasks, t);

    va_start(ap, component);
    while (component) {
        c = component_find(b->s->components, component);
        task_append(t, c);
        component = va_arg(ap, char *);
    }
    va_end(ap);
}
