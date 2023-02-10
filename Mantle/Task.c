#include "Task.h"
#include "Dynamic.h"
#include "Extras.h"
#include <stdlib.h>
#include <string.h>

Task *task_create(TASK_POINTER)
{
    Task *t;

    t = malloc(sizeof(Task));
    t->priority = 0;
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

int task_filter(List *cd, List *l)
{
    int i;
    int cfound;
    Component *c;

    cfound = 0;
    for (i = 0; l->length; ++i) {
        c = list_get(l, i);
        if (c == NULL)
            return 1;
        if (component_data_find(cd, c->name))
            ++cfound;
        if (cfound == l->length)
            return 0;
    }
    return 1;
}

void task_run(Store *s, Task *t, List *l)
{
    Entity *e;
    List *data;
    int i;
    
    for (i = 0; i < l->length; ++i) {
        e = list_get(l, i);
        data = entity_data_get(e);
        if (!task_filter(data, t->components))
            t->run(s, data, l);
        list_free(data);
    }
}
