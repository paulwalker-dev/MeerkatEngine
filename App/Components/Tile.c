#include "Tile.h"
#include <stdlib.h>

void *cd_tile_create()
{
    CD_INIT(Tile, cd);

    cd->x = cd->y = 0;
    cd->superposition = list_create();

    return cd;
}

void cd_tile_destroy(void *_cd)
{
    TileComponent *cd;
    cd = _cd;
    list_destroy(cd->superposition);
    free(cd);
}

Component *c_tile_create()
COMPONENT3(Tile,
        cd_tile_create,
        cd_tile_destroy);
