#include "Tile.h"
#include "EngineMantle.h"
#include "EngineGraphics.h"

#include "../Components/Tile.h"

void t_update_tile(Store *s, List *cd, List *e)
{
    TASK_CD(cd, Tile, cd_tile);
    TASK_CD(cd, Position, cd_position);
    TASK_CD(cd, Size, cd_size);
    TASK_CD(cd, GraphicsImage, cd_image);

    int n;

    n = cd_tile->n;
    if (!n) return;

    cd_size->w = n;
    cd_size->h = n;

    ++n;
    cd_position->x = cd_tile->x * n;
    cd_position->y = cd_tile->y * n;

    if (cd_image->texture)
        cd_tile->n = 0;
}
