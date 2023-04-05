#include "Image.h"
#include "EngineMantle.h"
#include <string.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "../Components/Image.h"
#include "../Components/Position.h"
#include "../Components/Size.h"
#include "../Components/Window.h"

void t_draw_image(Store *s, List *cd, List *e)
{
    TASK_E(e, GraphicsData, e_graphics);
    TASK_CD(cd, GraphicsImage, cd_image);
    TASK_CD(cd, Position, cd_position);
    TASK_CD(cd, Size, cd_size);
    TASK_CD(e_graphics->data, GraphicsWindow, cd_window);

    SDL_Rect rect;
    SDL_Texture *texture;

    if (!cd_image->texture) {
        if (cd_image->surface)
            SDL_FreeSurface(cd_image->surface);
        cd_image->surface = IMG_Load(cd_image->filename);
        cd_image->texture = SDL_CreateTextureFromSurface(
            cd_window->renderer, cd_image->surface
        );
        cd_size->w = cd_image->surface->w;
        cd_size->h = cd_image->surface->h;
    }
    
    rect.w = cd_size->w;
    rect.h = cd_size->h;
    rect.x = cd_position->x;
    rect.y = cd_position->y;

    SDL_RenderCopyEx(
        cd_window->renderer,
        cd_image->texture,
        NULL, &rect,
        0, NULL,
        cd_image->flip
    );
}
