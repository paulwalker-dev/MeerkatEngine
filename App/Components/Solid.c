#include "Solid.h"
#include <stdlib.h>

void *cd_solid_create()
{
    CD_INIT(Solid, cd);
    return cd;
}

Component *c_solid_create()
COMPONENT(Solid, cd_solid_create);
