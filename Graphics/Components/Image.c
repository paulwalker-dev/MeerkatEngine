#include "Image.h"
#include "EngineCore.h"
#include <stdio.h>
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
    GraphicsImageComponent *cd = _cd;

    if (cd->texture)
        SDL_DestroyTexture(cd->texture);
}

Component *c_graphics_image_create()
COMPONENT3(GraphicsImage,
           cd_graphics_image_create,
           cd_graphics_image_destroy);
