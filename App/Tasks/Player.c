#include "Player.h"
#include "EngineCore.h"
#include "EngineGraphics.h"
#include <math.h>
#include "SDL2/SDL.h"

#include "../Components/Player.h"

#define PI 3.14159265

void player_update_key(PlayerComponent *player, SDL_Keycode key, int pressed)
{
    if (key == player->up.key)
        player->up.pressed = pressed;
    if (key == player->down.key)
        player->down.pressed = pressed;
    if (key == player->left.key)
        player->left.pressed = pressed;
    if (key == player->right.key)
        player->right.pressed = pressed;
}

void t_player_move(Store *s, List *cd, List *e)
{
    TASK_E(e, GraphicsData, e_window);
    TASK_CD(cd, Player, cd_player);
    TASK_CD(cd, GraphicsPosition, cd_position);
    TASK_CD(e_window->data, GraphicsEvents, cd_events);
    SDL_Event *event;
    int i;
    float deg;

    for (i = 0; i < cd_events->events->length; ++i) {
        event = list_get(cd_events->events, i);
        if (event->type == SDL_KEYUP)
            player_update_key(cd_player, event->key.keysym.sym, 0);
        if (event->type == SDL_KEYDOWN)
            player_update_key(cd_player, event->key.keysym.sym, 1);
    }

    if (cd_player->left.pressed)
        cd_position->rotation -= 2 % 360;
    if (cd_player->right.pressed)
        cd_position->rotation += 2 % 360;

    if (cd_player->up.pressed) {
        cd_position->x += 3 * sin(cd_position->rotation * PI / 180);
        cd_position->y -= 3 * cos(cd_position->rotation * PI / 180);
    }
    
    if (cd_player->down.pressed) {
        cd_position->x -= 3 * sin(cd_position->rotation * PI / 180);
        cd_position->y += 3 * cos(cd_position->rotation * PI / 180);
    }
}
