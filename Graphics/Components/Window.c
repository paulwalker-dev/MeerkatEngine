#include "Window.h"
#include <stdlib.h>
#include <raylib.h>

void *cd_window_create()
{
    CD_INIT(Window, cd);
    InitWindow(680, 480, "MeerkatEngine");
    SetTargetFPS(60);
    return cd;
}

void cd_window_destroy(void *_cd)
{
    WindowComponent *cd;
    cd = _cd;
    CloseWindow();
    free(cd);
}

Component *c_window_create()
COMPONENT3(Window,
        cd_window_create,
        cd_window_destroy);
