#include "Dash.h"
#include <stdlib.h>

void *cd_dash_create()
{
    CD_INIT(Dash, cd);
    cd->enabled = 1;
    return cd;
}

Component *c_dash_create()
COMPONENT(Dash, cd_dash_create);
