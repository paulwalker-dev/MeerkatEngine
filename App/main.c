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

void init_player(Box *b)
{
    Entity *e_player;

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

    TASK_CD(e_player->data, Physics, cd_physics);
    cd_physics->stationary = 0;
}

void init_tile(Box *b, char *filename, int x, int y, int w, int h)
{
    Entity *e_floor;

    e_floor = box_entity(b, "Floor");

    TASK_CD(e_floor->data, GraphicsStitch, cd_stitch);
    cd_stitch->width = w;
    cd_stitch->height = h;
    cd_stitch->filenames = list_create();
    for (int i = 0; i < w * h; ++i) {
        list_append(cd_stitch->filenames, filename);
    }

    TASK_CD(e_floor->data, Position, cd_position);
    cd_position->x = 8 * x;
    cd_position->y = 8 * y;
}

int main(int argv, char *argc[])
{
    Box *b;
    Entity *e_player;
    Entity *e_floor;

    // Ensure assets can be accessed via relative paths
    chdir(dirname(argc[0]));

    b = box_create();

    physics_create(b);
    graphics_create(b);

    box_component(b, c_dash_create);
    box_component(b, c_player_create);
    box_archetype(b, "Player", "Player", "Dynamic", "Physics", "GraphicsStitch", "GraphicsImage", "Position", "Size", "Velocity", NULL);

    // BEGIN: Tile Initialization
    box_archetype(b, "Tile", "Physics", "Position", "Size", "Velocity", "GraphicsStitch", "GraphicsImage", NULL);
    init_tile(b, "assets/grass.qoi", 0, 17, 32, 1);
    // END: Tile Initialization
    
    // BEGIN: Player Initialization
    init_player(b);
    // END: Player Initialization


    box_task(b, t_player_move, "Player", "Physics", "Position", "Velocity", NULL);
    box_task(b, t_player_dash, "Dash", "Player", "Velocity", NULL);

    graphics_loop(b);
    box_destroy(b);

    return 0;
}
