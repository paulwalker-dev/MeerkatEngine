#include "Size.h"
#include <stdlib.h>

void *cd_size_create()
{
    CD_INIT(Size, cd);
    cd->w = 0;
    cd->h = 0;
    return cd;
}

Component *c_size_create()
COMPONENT(Size, cd_size_create);
