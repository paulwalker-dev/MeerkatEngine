#include "Window.h"
#include "EngineMantle.h"
#include "SDL2/SDL.h"

#include "../Components/Window.h"

void t_blank_window(Store *s, List *cd, List *e)
{
    TASK_CD(cd, GraphicsWindow, cd_window);
    SDL_SetRenderDrawColor(
        cd_window->renderer,
        0x00, 0x00, 0x00, 0xFF
    );
    SDL_RenderClear(cd_window->renderer);
}

void t_render(Store *s, List *cd, List *e)
{
    TASK_CD(cd, GraphicsWindow, cd_window);
    SDL_RenderPresent(cd_window->renderer);
}
