#include "Player.h"
#include "EngineMantle.h"
#include "EnginePhysics.h"
#include "EngineGraphics.h"
#include "SDL2/SDL.h"

#include "../Components/Input.h"
#include "../Components/Player.h"

// Shift by one from player_states
char *player_images[] = {
    "assets/" PLAYER_SOLID ".qoi",
    "assets/" PLAYER_LIQUID ".qoi"
};

void t_player_all(Store *s, List *cd, List *e)
{
    TASK_E(e, AppController, e_controller);
    TASK_CD(e_controller->data, Input, cd_input);
    TASK_CD(cd, Dynamic, cd_dynamic);
    TASK_CD(cd, Player, cd_player);
    TASK_CD(cd, GraphicsImage, cd_image);
    Component *c;
    char *state, *old_state;
    int i;

    if (input_key_status(cd_input, "state")) {
        i = cd_player->next;
        cd_player->state = player_states[i];

        if (!strcmp(player_states[++i], ""))
            i = 0;
        cd_player->next = i;

        input_key_hold(cd_input, "state");
    }

    state = cd_player->state;
    old_state = cd_player->old_state;

    if (strcmp(state, old_state)) {
        c = component_find(s->components, old_state);
        if (c) dynamic_drop(cd_dynamic, c->name);
        c = component_find(s->components, state);
        if (c) dynamic_append(cd_dynamic, c);
        cd_player->old_state = state;
        cd_image->filename = player_images[(cd_player->next + 1) % 2];
        SDL_DestroyTexture(cd_image->texture);
        cd_image->texture = NULL;
    }

    if (input_key_status(cd_input, "left"))
        cd_image->flip = SDL_FLIP_HORIZONTAL;
    if (input_key_status(cd_input, "right"))
        cd_image->flip = SDL_FLIP_NONE;
}
