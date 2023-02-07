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
    if (player->reset.key == key) target = &player->reset;
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
    TASK_CD(cd, Physics, cd_physics);
    TASK_CD(cd, Velocity, cd_velocity);
    TASK_CD(e_window->data, GraphicsEvents, cd_events);
    SDL_Event *event;
    float vx;
    int i;

    for (i = 0; i < cd_events->events->length; ++i) {
        event = list_get(cd_events->events, i);
        if (event->type == SDL_KEYUP)
            player_update_key(cd_player, event->key.keysym.sym, 0);
        if (event->type == SDL_KEYDOWN)
            player_update_key(cd_player, event->key.keysym.sym, 1);
    }

    if (cd_physics->floored) {
        cd_player->jump_count = 0;
    }

    if (cd_player->up.pressed == 1 && cd_player->jump_count++ < 2) {
        cd_velocity->vy = -6;
        cd_player->up.pressed = 2;
    }

    vx = cd_velocity->vx;

    if (cd_player->left.pressed == 1)
        vx = fminf(-2.5, vx);
    if (cd_player->right.pressed == 1)
        vx = fmaxf(2.5, vx);

    if (vx) {
        if (vx < 0) {
            vx += 0.5;
            if (vx < -16)
                vx = -16;
        }
        if (vx > 0) {
            vx -= 0.5;
            if (vx > 16)
                vx = 16;
        }
    }

    if (cd_player->reset.pressed == 1) {
        cd_position->x = 0;
        cd_position->y = 0;
        cd_player->reset.pressed = 2;
    }

    cd_velocity->vx = vx;
    cd_position->x += cd_velocity->vx;
    cd_position->y += cd_velocity->vy;
}
