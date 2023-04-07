#include "Map.h"
#include <stdlib.h>

void *cd_map_create()
{
    CD_INIT(Map, cd);
    cd->started = 0;
    return cd;
}

Component *c_map_create()
COMPONENT(Map, cd_map_create);
