#include "EngineMantle.h"
#include "EngineGraphics.h"
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>

void enable_fps(Box *b)
{
    TASK_E(b->s->entities, Graphics, e_graphics);
    TASK_CD(e_graphics->data, FPS, cd_fps);
    cd_fps->enabled = 1;
}

int main(int argv, char *argc[])
{
    Box *b;

    if (chdir(dirname(argc[0]))) return 1;
    b = box_create();

    graphics_create(b);
    box_priority(b, 0);

    enable_fps(b);

    graphics_loop(b);
    box_destroy(b);

    return 0;
}
