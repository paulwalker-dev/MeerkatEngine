#include "Task.h"
#include <stdlib.h>

Task *task_create(void (* run)(List *cd))
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
