#include "Physics.h"
#include <stdlib.h>

void *cd_physics_create()
{
    CD_INIT(Physics, cd);
    cd->id = generate_id();
    cd->stationary = 1;
    return cd;
}

Component *c_physics_create()
COMPONENT(Physics, cd_physics_create);
