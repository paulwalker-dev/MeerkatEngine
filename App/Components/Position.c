#include "Position.h"
#include <stdlib.h>

void *position_cd_create()
{
    PositionComponent *cd;

    cd = malloc(sizeof(PositionComponent));
    cd->x = 0;
    cd->y = 0;
    return cd;
}
