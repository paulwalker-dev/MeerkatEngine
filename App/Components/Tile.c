#include "Tile.h"
#include <stdlib.h>

void *cd_tile_create()
{
    CD_INIT(Tile, cd);

    cd->x = cd->y = 0;
    cd->n = 3;

    return cd;
}

Component *c_tile_create()
COMPONENT(Tile, cd_tile_create);
