#include "Position.h"
#include "EngineCore.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

void *cd_graphics_position_create()
{
    CD_INIT(GraphicsPosition, cd);
    cd->x = cd->y = 0;
    return cd;
}

Component *c_graphics_position_create()
COMPONENT(GraphicsPosition, cd_graphics_position_create);
