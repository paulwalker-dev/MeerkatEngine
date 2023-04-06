#include "EngineMantle.h"
#include "EngineGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>

#include "Components/Tile.h"

#include "Tasks/Tile.h"

int main(int argv, char *argc[])
{
    Box *b;

    if (chdir(dirname(argc[0]))) return 1;
    b = box_create();

    graphics_create(b);
    box_priority(b, 0);

    box_component(b, c_tile_create);
    box_archetype(b, "Tile", "Tile", "Dynamic", "GraphicsImage", "Size", "Position", NULL);
    box_entity(b, "Tile");
    box_task(b, t_update_tile, "Tile", "Dynamic", NULL);

    graphics_loop(b);
    box_destroy(b);

    return 0;
}
