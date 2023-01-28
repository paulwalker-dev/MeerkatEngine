#include "Position.h"

void *cd_position_create()
{
    CD_INIT(Position, cd);
    cd->x = 0;
    cd->y = 0;
    return cd;
}

Component *c_position_create()
COMPONENT(Position, cd_position_create);
