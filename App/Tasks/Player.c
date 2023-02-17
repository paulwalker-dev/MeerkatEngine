#include "Player.h"
#include "EngineMantle.h"
#include "EnginePhysics.h"
#include "EngineGraphics.h"
#include "SDL2/SDL.h"

#include "../Components/Input.h"
#include "../Components/Player.h"

void t_player_all(Store *s, List *cd, List *e)
{
    TASK_E(e, AppController, e_controller);
    TASK_CD(e_controller->data, Input, cd_input);
    TASK_CD(cd, Dynamic, cd_dynamic);
    TASK_CD(cd, Player, cd_player);
    TASK_CD(cd, GraphicsImage, cd_image);
    Component *c;
    char *state, *old_state;

    state = cd_player->state;
    old_state = cd_player->old_state;

    if (strcmp(state, old_state)) {
        // dynamic_drop only drops component if in dynamic
        dynamic_drop(cd_dynamic, old_state);
        c = component_find(s->components, state);
        if (c) dynamic_append(cd_dynamic, c);
        cd_player->old_state = state;
    }

    if (input_key_status(cd_input, "left"))
        cd_image->flip = SDL_FLIP_HORIZONTAL;
    if (input_key_status(cd_input, "right"))
        cd_image->flip = SDL_FLIP_NONE;
}
