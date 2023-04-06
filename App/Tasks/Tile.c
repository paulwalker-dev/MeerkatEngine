#include "Tile.h"
#include "EngineMantle.h"

#include "../Components/Tile.h"

void t_update_tile(Store *s, List *cd, List *e)
{
    TASK_CD(cd, Tile, cd_tile);
    TASK_CD(cd, Dynamic, cd_dynamic);
}
