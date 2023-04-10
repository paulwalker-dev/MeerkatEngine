#include "Window.h"
#include <raylib.h>

void *cd_window_create()
{
    CD_INIT(Window, cd);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "MeerkatEngine");
    SetTargetFPS(60);
    return cd;
}

void cd_window_destroy(void *cd)
{
    CloseWindow();
    free(cd);
}

Component *c_window_create()
COMPONENT3(Window,
        cd_window_create,
        cd_window_destroy);
