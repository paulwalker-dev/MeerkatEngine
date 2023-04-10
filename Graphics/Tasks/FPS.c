#include "EngineMantle.h"
#include <raylib.h>

#include "../Components/FPS.h"

void t_fps(Store *s, List *cd, List *e)
{
    TASK_CD(cd, FPS, cd_fps);

    if (cd_fps->enabled)
        DrawFPS(16, 16);
}
