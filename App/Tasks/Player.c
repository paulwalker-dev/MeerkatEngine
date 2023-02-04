#include "Player.h"
#include "EngineCore.h"
#include "EnginePhysics.h"
#include "EngineGraphics.h"
#include <math.h>
#include "SDL2/SDL.h"

#include "../Components/Player.h"

#define PI 3.14159265

void player_update_key(PlayerComponent *player, SDL_Keycode key, int pressed)
{
    PlayerKey *target = NULL;
    if (player->up.key == key) target = &player->up;
    if (player->down.key == key) target = &player->down;
    if (player->left.key == key) target = &player->left;
    if (player->right.key == key) target = &player->right;
    if (target) {
        if (target->pressed < 2)
            target->pressed = pressed;
        else if (pressed == 0)
            target->pressed = 0;
    }
}

void t_player_move(Store *s, List *cd, List *e)
{
    TASK_E(e, GraphicsData, e_window);
    TASK_CD(cd, Player, cd_player);
    TASK_CD(cd, Position, cd_position);
    TASK_CD(cd, Velocity, cd_velocity);
    TASK_CD(e_window->data, GraphicsEvents, cd_events);
    SDL_Event *event;
    int i;

    for (i = 0; i < cd_events->events->length; ++i) {
        event = list_get(cd_events->events, i);
        if (event->type == SDL_KEYUP)
            player_update_key(cd_player, event->key.keysym.sym, 0);
        if (event->type == SDL_KEYDOWN)
            player_update_key(cd_player, event->key.keysym.sym, 1);
    }

    if (cd_player->up.pressed == 1) {
        cd_velocity->vy -= 6;
        cd_player->up.pressed = 2;
    }
    if (cd_player->left.pressed)
        cd_position->x -= 1;
    if (cd_player->right.pressed)
        cd_position->x += 1;

    cd_position->y += cd_velocity->vy;
}
