#include "EngineMantle.h"
#include "EngineGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>

#include "Components/Map.h"
#include "Components/Tile.h"

#include "Tasks/Map.h"
#include "Tasks/Tile.h"

void create_map(Box *b)
{
    Entity *e_map;

    box_component(b, c_map_create);
    box_archetype(b, "Map", "Map", "GraphicsImage", "Size", NULL);
    e_map = box_entity(b, "Map");
    TASK_CD(e_map->data, GraphicsImage, cd_image);
    cd_image->filename = "assets/map.qoi";
    box_task(b, t_update_map, "Map", "GraphicsImage", "Size", NULL);
}

int main(int argv, char *argc[])
{
    Box *b;

    if (chdir(dirname(argc[0]))) return 1;
    b = box_create();

    graphics_create(b);
    box_priority(b, 0);

    box_component(b, c_tile_create);
    box_archetype(b, "Tile", "Tile", "GraphicsImage", "Size", "Position", NULL);
    create_map(b);
    box_task(b, t_update_tile, "Tile", "GraphicsImage", "Size", "Position", NULL);

    graphics_loop(b);
    box_destroy(b);

    return 0;
}
