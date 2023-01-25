#include "Component.h"
#include <stdio.h>
#include <stdlib.h>

void *default_cd_create()
{
    printf("ERROR: Default Component Data function used!\n");
    exit(1);
}

void default_cd_destroy(void *cd)
{
    free(cd);
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
