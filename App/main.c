#include "EngineCore.h"
#include "EngineMantle.h"
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

typedef struct {
    int x;
    int y;
} VelocityComponent;

void *cd_velocity_create()
{
    VelocityComponent *cd;

    cd = malloc(sizeof(VelocityComponent));
    cd->x = 0;
    cd->y = 0;
    return cd;
}

Component *c_velocity_create()
{
    Component *c;

    c = component_create("Velocity");
    c->data_init = cd_velocity_create;
    return c;
}

void t_move_run(List *l)
{
    TASK_CD(Position, position_cd);

    position_cd->x++;
    position_cd->y--;
}

void t_info_run(List *l)
{
    TASK_CD(Position, position_cd);
    TASK_CD(Velocity, velocity_cd);

    printf("Position: { x: %d, y: %d }\n",
           position_cd->x,
           position_cd->y);

    printf("Velocity: { x: %d, y: %d }\n",
           velocity_cd->x,
           velocity_cd->y);
}

int main()
{
    Box *b;

    b = box_create();

    box_component(b, c_position_create);
    box_component(b, c_velocity_create);
    box_archetype(b, "Cube", "Position", "Velocity", 0);
    box_entity(b, "Cube");
    box_task(b, t_move_run, "Position", 0);
    box_task(b, t_info_run, "Position", "Velocity", 0);

    box_update(b);

    box_destroy(b);
}
