#include "Image.h"
#include <stdlib.h>
#include "SDL2/SDL.h"

void *cd_graphics_image_create()
{
    CD_INIT(GraphicsImage, cd);

    cd->filename = "assets/default.qoi";
    cd->surface = NULL;
    cd->texture = NULL;

    return cd;
}

Component *c_graphics_image_create()
COMPONENT(GraphicsImage,
          cd_graphics_image_create);
