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

void cd_graphics_image_destroy(void *_cd)
{
    GraphicsImageComponent *cd;
    cd = _cd;

    if (cd->surface)
        SDL_FreeSurface(cd->surface);

    free(cd);
}

Component *c_graphics_image_create()
COMPONENT3(GraphicsImage,
           cd_graphics_image_create,
           cd_graphics_image_destroy);
