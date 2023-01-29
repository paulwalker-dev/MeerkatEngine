#include "Image.h"
#include "EngineCore.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

void *cd_graphics_image_create()
{
    CD_INIT(GraphicsImage, cd);

    cd->filename = "App/assets/text.bmp";
    cd->surface = SDL_LoadBMP(cd->filename);

    return cd;
}

void cd_graphics_image_destroy(void *_cd)
{
    GraphicsImageComponent *cd = _cd;

    if (cd->surface)
        SDL_FreeSurface(cd->surface);
}

Component *c_graphics_image_create()
COMPONENT3(GraphicsImage,
           cd_graphics_image_create,
           cd_graphics_image_destroy);
