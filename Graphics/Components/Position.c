#include "Position.h"
#include <stdlib.h>

void *cd_position_create()
{
    CD_INIT(Position, cd);
    cd->x = cd->y = 0;
    return cd;
}

Component *c_position_create()
COMPONENT(Position, cd_position_create);
