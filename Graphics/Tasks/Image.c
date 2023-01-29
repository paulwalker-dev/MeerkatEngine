#include "Image.h"
#include "../Components/Image.h"
#include "../Components/Position.h"
#include "../Components/Size.h"
#include "../Components/Window.h"
#include <string.h>
#include "SDL2/SDL.h"

void t_draw_image(List *cd, List *e)
{
    TASK_E(e, GraphicsData, e_graphics);
    TASK_CD(cd, GraphicsImage, cd_image);
    TASK_CD(cd, GraphicsPosition, cd_position);
    TASK_CD(cd, GraphicsSize, cd_size);
    TASK_CD(e_graphics->data, GraphicsWindow, cd_window);

    SDL_Rect rect;

    if (!cd_image->texture) {
        cd_image->surface = SDL_LoadBMP(cd_image->filename);
        cd_image->texture = SDL_CreateTextureFromSurface(
            cd_window->renderer, cd_image->surface
        );
        SDL_FreeSurface(cd_image->surface);
    }

    rect.x = cd_position->x;
    rect.y = cd_position->y;
    rect.w = cd_size->width;
    rect.h = cd_size->height;

    SDL_RenderSetViewport(
        cd_window->renderer,
        &rect
    );

    SDL_RenderCopy(
        cd_window->renderer,
        cd_image->texture,
        NULL, NULL
    );

    SDL_RenderSetViewport(
        cd_window->renderer,
        NULL
    );
}
