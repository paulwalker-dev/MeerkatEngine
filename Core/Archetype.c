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
