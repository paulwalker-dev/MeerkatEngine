#include "EngineMantle.h"
#include "EngineGraphics.h"
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>

#include "Components/FPS.h"

#include "Tasks/FPS.h"

void box_app(Box *b)
{
    Entity *e_app;

    box_component(b, c_fps_create);
    box_task(b, t_fps, "FPS", NULL);

    box_archetype(b, "App", "FPS", NULL);
    e_app = box_entity(b, "App");
    TASK_CD(e_app->data, FPS, cd_fps);
    cd_fps->enabled = 1;
}

int main(int argv, char *argc[])
{
    Box *b;

    if (chdir(dirname(argc[0]))) return 1;
    b = box_create();

    graphics_create(b);
    box_priority(b, 0);

    box_app(b);

    graphics_loop(b);
    box_destroy(b);

    return 0;
}
