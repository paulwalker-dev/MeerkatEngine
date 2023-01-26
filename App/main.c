#include "EngineCore.h"
#include <stdio.h>
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

void t_move_run(List *l)
{
    TASK_CD(Position, position_cd);

    position_cd->x++;
    position_cd->y--;
}

Task *t_move_create(List *c)
{
    Component *position_c;
    Task *t;

    position_c = component_find(c, "Position");

    t = task_create(t_move_run);
    task_append(t, position_c);
    return t;
}

void t_info_run(List *l)
{
    TASK_CD(Position, position_cd);

    printf("x: %d, y: %d\n",
           position_cd->x,
           position_cd->y);
}

Task *t_info_create(List *c)
{
    Component *position_c;
    Task *t;

    position_c = component_find(c, "Position");

    t = task_create(t_info_run);
    task_append(t, position_c);
    return t;
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

    // Task initialization
    store_task(s, t_move_create);
    store_task(s, t_info_create);

    store_update(s);

    store_destroy(s);
}
