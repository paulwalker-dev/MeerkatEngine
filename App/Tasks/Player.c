#include "Player.h"
#include "EngineMantle.h"
#include "EnginePhysics.h"
#include "EngineGraphics.h"
#include "SDL2/SDL.h"

#include "../Components/Input.h"

void t_player_all(Store *s, List *cd, List *e)
{
    TASK_E(e, AppController, e_controller);
    TASK_CD(e_controller->data, Input, cd_input);
    TASK_CD(cd, GraphicsImage, cd_image);

    if (input_key_status(cd_input, "left"))
        cd_image->flip = SDL_FLIP_HORIZONTAL;
    if (input_key_status(cd_input, "right"))
        cd_image->flip = SDL_FLIP_NONE;
}
