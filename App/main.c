#include "EngineCore.h"
#include "EngineMantle.h"
#include "EngineGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>

#include "Components/Player.h"

#include "Tasks/Player.h"

void t_info_run(List *cd, List *e)
{
    TASK_CD(cd, GraphicsPosition, cd_position);
    
    printf("Position: { x: %d, y: %d }\n",
           cd_position->x,
           cd_position->y);
}

int main(int argv, char *argc[])
{
    Box *b;
    Entity *e_player;

    // Ensure assets can be accessed via relative paths
    chdir(dirname(argc[0]));

    b = box_create();

    graphics_create(b);

    box_component(b, c_player_create);
    box_archetype(b, "Player", "Player", "GraphicsImage", "GraphicsPosition", "GraphicsSize", 0);
    e_player = box_entity(b, "Player");
    TASK_CD(e_player->data, GraphicsImage, cd_image);
    cd_image->filename = "assets/sun.qoi";

    box_task(b, t_player_move, "GraphicsEvents", 0);

    graphics_loop(b);
    graphics_destroy(b);
    box_destroy(b);
}
