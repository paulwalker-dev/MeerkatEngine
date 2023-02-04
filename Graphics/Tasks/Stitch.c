#include "Stitch.h"
#include "EngineMantle.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "../Components/Image.h"
#include "../Components/Stitch.h"
#include "../Components/Window.h"

void t_stitch_image(Store *s, List *cd, List *e)
{
    TASK_E(e, GraphicsData, e_window);
    TASK_CD(e_window->data, GraphicsWindow, cd_window);
    TASK_CD(cd, GraphicsImage, cd_image);
    TASK_CD(cd, GraphicsStitch, cd_stitch);
    SDL_Surface *surface;
    SDL_Rect rect;
    char *filename;
    int x, y, i;
    int w, h;

    if (!cd_stitch->filenames)
        return;
    if (cd_image->surface)
        return;
    
    w = cd_stitch->width;
    h = cd_stitch->height;
    x = w * cd_stitch->tile_width;
    y = h * cd_stitch->tile_height;
    cd_image->surface = SDL_CreateRGBSurface(
        0, x, y, 32, 0, 0, 0, 0
    );
    
    for (x = 0; x < w; ++x)
        for (y = 0; y < h; ++y) {
            i = x + (y * w);
            filename = list_get(cd_stitch->filenames, i);
            if (!filename) return;
            surface = IMG_Load(filename);
            
            rect.w = cd_stitch->tile_width;
            rect.h = cd_stitch->tile_height;
            rect.x = x * rect.w;
            rect.y = y * rect.h;
            SDL_BlitSurface(
                surface, NULL,
                cd_image->surface, &rect
            );

            SDL_FreeSurface(surface);
        }
    
    if (cd_image->texture)
        SDL_DestroyTexture(cd_image->texture);
    cd_image->texture = SDL_CreateTextureFromSurface(
        cd_window->renderer, cd_image->surface
    );
}
