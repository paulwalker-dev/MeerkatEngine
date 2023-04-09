#include "EngineMantle.h"
#include "EngineGraphics.h"
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>

int main(int argv, char *argc[])
{
    Box *b;

    if (chdir(dirname(argc[0]))) return 1;
    b = box_create();

    graphics_create(b);
    box_priority(b, 0);

    graphics_loop(b);
    box_destroy(b);

    return 0;
}
