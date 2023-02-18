#include "Dynamic.h"
#include <stdlib.h>

Dynamic *dynamic_create()
{
    Dynamic *d;

    d = malloc(sizeof(Dynamic));
    d->components = list_create();
    d->data = list_create();

    return d;
}

void dynamic_destroy(Dynamic *d)
{
    ComponentData *cd;
    int i;

    for (i = 0; i < d->data->length; ++i) {
        cd = list_get(d->data, i);
        dynamic_drop(d, cd->name);
    }

    list_free(d->components);
    list_free(d->data);
    free(d);
}

void dynamic_append(Dynamic *d, Component *c)
{
    ComponentData *cd;

    cd = component_data_create(c);
    list_append(d->components, c);
    list_append(d->data, cd);
}

void dynamic_drop(Dynamic *d, char *name)
{
    Component *c;
    ComponentData *cd;
    int i, j;

    c = NULL;
    for (i = 0; i < d->components->length; ++i) {
        c = list_get(d->components, i);
        if (!c) return;
        if (c->name == name) break;
    }

    cd = NULL;
    for (j = 0; i < d->data->length; ++i) {
        cd = list_get(d->data, i);
        if (!cd) return;
        if (cd->name == name) break;
    }

    if (c && cd) {
        component_data_destroy(c, cd);
        list_pop(d->components, i);
        list_pop(d->data, j);
    }
}

void *cd_dynamic_create()
{
    return dynamic_create();
}

void cd_dynamic_destroy(void *cd)
{
    dynamic_destroy(cd);
}

Component *c_dynamic_create()
COMPONENT3(Dynamic,
           cd_dynamic_create,
           cd_dynamic_destroy);
