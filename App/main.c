#include "EngineCore.h"
#include "EngineMantle.h"
#include "EngineGraphics.h"
#include <stdio.h>
#include <stdlib.h>

void t_move_run(List *cd, List *e)
{
    TASK_CD(cd, GraphicsPosition, cd_position);

    cd_position->x++;
    cd_position->y++;
}

void t_info_run(List *cd, List *e)
{
    TASK_CD(cd, GraphicsPosition, cd_position);
    
    printf("Position: { x: %d, y: %d }\n",
           cd_position->x,
           cd_position->y);
}

int main()
{
    Box *b;
    Entity *e_image;

    b = box_create();

    graphics_create(b);

    box_archetype(b, "Image", "GraphicsImage", "GraphicsPosition", "GraphicsSize", 0);
    e_image = box_entity(b, "Image");
    TASK_CD(e_image->data, GraphicsImage, cd_image);
    cd_image->filename = "App/assets/sun.bmp";

    box_task(b, t_move_run, "GraphicsPosition", 0);
    box_task(b, t_info_run, "GraphicsPosition", 0);

    graphics_loop(b);

    graphics_destroy(b);
    box_destroy(b);
}
