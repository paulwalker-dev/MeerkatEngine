#include "EngineCore.h"
#include "EngineMantle.h"
#include "EngineGraphics.h"
#include <stdio.h>
#include <stdlib.h>

#include "Components/Position.h"

void t_move_run(List *l)
{
    TASK_CD(l, Position, cd_position);

    cd_position->x++;
    cd_position->y--;
}

void t_info_run(List *l)
{
    TASK_CD(l, Position, cd_position);
    
    printf("Position: { x: %d, y: %d }\n",
           cd_position->x,
           cd_position->y);
}

int main()
{
    Box *b;

    b = box_create();

    graphics_create(b);

    box_component(b, c_position_create);
    box_archetype(b, "Cube", "Position", 0);
    box_entity(b, "Cube");
    box_task(b, t_move_run, "Position", 0);
    box_task(b, t_info_run, "Position", 0);

    graphics_loop(b);

    graphics_destroy(b);
    box_destroy(b);
}
