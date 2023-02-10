#include "EngineMantle.h"
#include "EnginePhysics.h"
#include "EngineGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>

#include "Components/Input.h"

#include "Tasks/Input.h"

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

    box_priority(b, 0);

    box_component(b, c_input_create);
    box_archetype(b, "AppController", "Input", NULL);
    box_entity(b, "AppController");
    box_task(b, t_update_input, "Input", NULL);

    // BEGIN: Tile Initialization
    box_archetype(b, "Tile", "Physics", "Position", "Size", "GraphicsStitch", "GraphicsImage", NULL);
    init_tile(b, "assets/grass.qoi", 1, 17, 30, 1);
    init_tile(b, "assets/stone.qoi", 0, 0, 1, 18);
    init_tile(b, "assets/stone.qoi", 31, 0, 1, 18);
    init_tile(b, "assets/stone.qoi", 16, 9, 5, 3);
    // END: Tile Initialization

    graphics_loop(b);
    box_destroy(b);

    return 0;
}
