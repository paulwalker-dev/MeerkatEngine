#include "Archetype.h"
#include <stdlib.h>
#include <string.h>

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

void archetype_cleanup(void *a)
{
    archetype_destroy(a);
}

Archetype *archetype_find(List *l, char *name)
{
    int i;
    Archetype *a;

    for (i = 0; i < l->length; ++i) {
        a = list_get(l, i);

        /* Remember strcmp returns 0 when identical */
        if (!strcmp(a->name, name))
            return a;
    }
    return NULL;
}

void archetype_append(Archetype *a, Component *c)
{
    list_append(a->components, c);
}

Component *archetype_get(Archetype *a, char *name)
{
    return component_find(a->components, name);
}
