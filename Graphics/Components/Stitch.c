#include "Stitch.h"
#include <stdlib.h>

void *cd_graphics_stitch_create()
{
    CD_INIT(GraphicsStitch, cd);
    cd->tile_width = 8;
    cd->tile_height = 8;
    cd->width = 1;
    cd->height = 1;
    cd->filenames = NULL;
    return cd;
}

void cd_graphics_stitch_destroy(void *_cd)
{
    GraphicsStitchComponent *cd;
    cd = _cd;

    list_free(cd->filenames);
    free(cd);
}

Component *c_graphics_stitch_create()
COMPONENT3(GraphicsStitch,
           cd_graphics_stitch_create,
           cd_graphics_stitch_destroy);
