#include "Archetype.h"
#include <stdlib.h>

Archetype *archetype_create(char *name)
{
    Archetype *a;

    a = malloc(sizeof(Archetype));
    a->name = name;
    a->components = list_create();

    return a;
}

void archetype_destroy(Archetype *a)
{
    list_free(a->components);
    free(a);
}

Component *archetype_get(Archetype *a, char *name)
{
    int i;
    Component *c;

    for (i = 0; i < a->components->length; ++i) {
        c = list_get(a->components, i);
        if (c->name == name)
            return c;
    }
    return NULL;
}
