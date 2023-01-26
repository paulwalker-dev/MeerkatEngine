#include "EngineCore.h"
#include <stdlib.h>

typedef struct {
    int x, y;
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

int main()
{
    Store *s;
    Component *position_c;
    Archetype *cube_a;
    Entity *cube_e;

    s = store_create();

    // Component initialization
    position_c = store_component(s, c_position_create);

    // Archetype initialization
    cube_a = store_archetype(s, a_cube_create);

    // Entity initialization
    cube_e = entity_create(cube_a);
    list_append(s->entities, cube_e);

    store_destroy(s);
}
