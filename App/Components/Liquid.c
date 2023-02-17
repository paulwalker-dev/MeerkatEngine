#include "Liquid.h"
#include <stdlib.h>

void *cd_liquid_create()
{
    CD_INIT(Liquid, cd);
    return cd;
}

Component *c_liquid_create()
COMPONENT(Liquid, cd_liquid_create);
