#include "Position.h"
#include <stdlib.h>

void *cd_position_create()
{
    PositionComponent *cd;

    cd = malloc(sizeof(PositionComponent));
    cd->x = 0;
    cd->y = 0;
    return cd;
}

Component *c_position_create()
{
    Component *c;

    c = component_create("Position");
    c->data_init = cd_position_create;
    return c;
}
