#include "Velocity.h"
#include <stdlib.h>

void *cd_velocity_create()
{
    CD_INIT(Velocity, cd);
    cd->vx = 0;
    cd->vy = 0;
    return cd;
}

Component *c_velocity_create()
COMPONENT(Velocity, cd_velocity_create);
