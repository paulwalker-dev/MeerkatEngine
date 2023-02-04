#include "EngineMantle.h"
#include "EnginePhysics.h"
#include "EngineGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>

#include "Components/Dash.h"
#include "Components/Player.h"

#include "Tasks/Dash.h"
#include "Tasks/Player.h"

void t_info_run(List *cd, List *e)
{
    TASK_CD(cd, Position, cd_position);
    
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

    physics_create(b);
    graphics_create(b);

    box_component(b, c_dash_create);
    box_component(b, c_player_create);
    box_archetype(b, "Player", "Player", "Dynamic", "GraphicsStitch", "GraphicsImage", "Position", "Velocity", NULL);

    e_player = box_entity(b, "Player");

    TASK_CD(e_player->data, GraphicsStitch, cd_stitch);
    cd_stitch->width  = 1;
    cd_stitch->height = 2;
    cd_stitch->filenames = list_create();
    list_append(cd_stitch->filenames, "assets/player_head_center.qoi");
    list_append(cd_stitch->filenames, "assets/player_body.qoi");

    TASK_CD(e_player->data, Player, cd_player);
    cd_player->up.key = SDLK_SPACE;

    TASK_CD(e_player->data, Dynamic, cd_dynamic);
    dynamic_append(cd_dynamic, component_find(b->s->components, "Dash"));

    box_task(b, t_player_move, "Player", "Position", "Velocity", NULL);
    box_task(b, t_player_dash, "Dash", "Player", "Velocity", NULL);

    graphics_loop(b);
    box_destroy(b);

    return 0;
}
