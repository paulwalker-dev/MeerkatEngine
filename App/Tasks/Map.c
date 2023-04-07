#include "Map.h"
#include "EngineMantle.h"
#include "EngineGraphics.h"

#include "../Components/Map.h"
#include "../Components/Tile.h"

void t_update_map(Store *s, List *cd, List *e)
{
    TASK_CD(cd, Map, cd_map);
    TASK_CD(cd, GraphicsImage, cd_image);
    TASK_CD(cd, Size, cd_size);

    Entity *e_tile;
    int x;

    if (!cd_image->texture)
        return;

    if (cd_map->started)
        return;
    cd_map->started = 1;

    for (x = 0; x < cd_size->w; ++x) {
        e_tile = store_entity(s, "Tile");
        TASK_CD(e_tile->data, Tile, cd_tile);
        cd_tile->x = x;
        cd_tile->y = 0;
        cd_tile->n = 10;
    }
}
