#include "FPS.h"
#include <stdlib.h>
#include <raylib.h>

void *cd_fps_create()
{
    CD_INIT(FPS, cd);
    cd->enabled = 0;
    return cd;
}

Component *c_fps_create()
COMPONENT(FPS, cd_fps_create);
