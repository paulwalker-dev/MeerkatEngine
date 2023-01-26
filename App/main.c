#include "EngineCore.h"
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} PositionComponent;

void *cd_position_create()
{
    PositionComponent *cd;

    cd = malloc(sizeof(PositionComponent));
    cd->x = 0;
    cd->y = 0;
    return cd;
}

Component *c_position_create()
{
    Component *c;

    c = component_create("Position");
    c->data_init = cd_position_create;
    return c;
}

Archetype *a_cube_create(List *c)
{
    Archetype *a;
    Component *position_c;

    position_c = component_find(c, "Position");

    a = archetype_create("Cube");
    archetype_append(a, position_c);
    return a;
}

Entity *e_cube_create(List *a)
{
    Entity *e;
    Archetype *cube_a;

    cube_a = archetype_find(a, "Cube");
    e = entity_create(cube_a);
    return e;
}

int main()
{
    Store *s;

    s = store_create();

    // Component initialization
    store_component(s, c_position_create);

    // Archetype initialization
    store_archetype(s, a_cube_create);

    // Entity initialization
    store_entity(s, e_cube_create);

    store_destroy(s);
}
