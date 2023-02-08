#include "EngineMantle.h"
#include "EnginePhysics.h"
#include "EngineGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>

#include "Components/Player.h"

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

    TASK_CD(e_player->data, GraphicsImage, cd_image);
    cd_image->filename = "assets/player.qoi";

    TASK_CD(e_player->data, Player, cd_player);
    cd_player->up.key = SDLK_SPACE;

    TASK_CD(e_player->data, Physics, cd_physics);
    cd_physics->stationary = 0;

    TASK_CD(e_player->data, Position, cd_position);
    cd_position->x = 16;
    cd_position->y = 16;
}

void init_tile(Box *b, char *filename, int x, int y, int w, int h)
{
    Entity *e_floor;

    e_floor = box_entity(b, "Tile");

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

    box_component(b, c_player_create);

    // BEGIN: Tile Initialization
    box_archetype(b, "Tile", "Physics", "Position", "Size", "GraphicsStitch", "GraphicsImage", NULL);
    init_tile(b, "assets/grass.qoi", 1, 17, 30, 1);
    init_tile(b, "assets/stone.qoi", 0, 0, 1, 18);
    init_tile(b, "assets/stone.qoi", 31, 0, 1, 18);
    init_tile(b, "assets/stone.qoi", 16, 9, 5, 3);
    // END: Tile Initialization
    
    // BEGIN: Player Initialization
    box_archetype(b, "Player", "Player", "Dynamic", "Physics", "GraphicsImage", "Position", "Size", "Velocity", NULL);
    init_player(b);
    // END: Player Initialization

    box_task(b, t_player_move, "Player", "Physics", "Position", "Velocity", "GraphicsImage", NULL);

    graphics_loop(b);
    box_destroy(b);

    return 0;
}
