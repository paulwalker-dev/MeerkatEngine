#include "Size.h"
#include "EngineCore.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

void *cd_graphics_size_create()
{
    CD_INIT(GraphicsSize, cd);

    cd->width = 64;
    cd->height = 64;
    
    return cd;
}

Component *c_graphics_size_create()
COMPONENT(GraphicsSize, cd_graphics_size_create);
