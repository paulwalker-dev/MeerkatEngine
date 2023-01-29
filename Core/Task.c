#include "Task.h"
#include "Archetype.h"
#include "Entity.h"
#include <stdlib.h>

Task *task_create(void (* run)(List *cd, List *e))
{
    Task *t;

    t = malloc(sizeof(Task));
    t->components = list_create();
    t->run = run;
    return t;
}

void task_destroy(Task *t)
{
    list_free(t->components);
    free(t);
}

void task_cleanup(void *t)
{
    task_destroy(t);
}

void task_append(Task *t, Component *c)
{
    list_append(t->components, c);
}

int task_filter(Archetype *a, List *l)
{
    int i;
    int cfound;
    Component *c;

    cfound = 0;
    for (i = 0; l->length; ++i) {
        c = list_get(l, i);
        if (c == NULL)
            return 1;
        if (archetype_get(a, c->name))
            ++cfound;
        if (cfound == l->length)
            return 0;
    }
    return 1;
}

void task_run(Task *t, List *l)
{
    int i;
    Archetype *a;
    Entity *e;
    List *filtered_e;

    filtered_e = list_create();
    for (i = 0; i < l->length; ++i) {
        e = list_get(l, i);
        a = e->archetype;
        if (!task_filter(a, t->components))
            list_append(filtered_e, e);
    }

    while (filtered_e->length) {
        e = list_pop(filtered_e, 0);
        t->run(e->data, l);
    }

    list_destroy(filtered_e);
}
