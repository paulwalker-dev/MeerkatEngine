#include "Image.h"
#include "../Components/Image.h"
#include "../Components/Window.h"
#include <string.h>
#include "SDL2/SDL.h"

void t_image_update(List *cd, List *e)
{
    TASK_E(e, GraphicsData, e_graphics);
    TASK_CD(cd, GraphicsImage, cd_image);
    TASK_CD(e_graphics->data, GraphicsWindow, cd_window);
    
    SDL_BlitSurface(
        cd_image->surface, NULL,
        cd_window->surface, NULL
    );
}
