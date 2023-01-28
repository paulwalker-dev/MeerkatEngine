#include "Component.h"
#include "lib/Panic.h"
#include <stdlib.h>
#include <string.h>

void *default_cd_create()
{
    panic("Default Component Data function used!\n");
}

void default_cd_destroy(void *cd)
{
    free(cd);
}

void component_cleanup(void *c)
{
    component_destroy(c);
}

Component *component_find(List *l, char *name)
{
    int i;
    Component *c;

    for (i = 0; i < l->length; ++i) {
        c = list_get(l, i);

        // Remember strcmp returns 0 when identical
        if (c && !strcmp(c->name, name))
            return c;
    }
    return NULL;
}

Component *component_create(char *name)
{
    Component *c;

    c = malloc(sizeof(Component));
    c->name = name;
    c->data_init = default_cd_create;
    c->data_destroy = default_cd_destroy;

    return c;
}

void component_destroy(Component *a)
{
    free(a);
}

ComponentData *component_data_create(Component *c)
{
    ComponentData *cd;

    cd = malloc(sizeof(ComponentData));
    cd->name = c->name;
    cd->data = c->data_init();

    return cd;
}

void component_data_destroy(Component *c, ComponentData *cd)
{
    c->data_destroy(cd->data);
    free(cd);
}

ComponentData *component_data_find(List *l, char *name)
{
    int i;
    ComponentData *cd;

    for (i = 0; i < l->length; ++i) {
        cd = list_get(l, i);

        // Remember strcmp returns 0 when identical
        if (!strcmp(cd->name, name))
            return cd;
    }
    return NULL;
}
