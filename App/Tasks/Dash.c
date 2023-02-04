#include "Dash.h"
#include "EngineMantle.h"
#include "EnginePhysics.h"

#include "../Components/Dash.h"
#include "../Components/Player.h"

void t_player_dash(Store *s, List *cd, List *e)
{
    TASK_CD(cd, Dash, cd_dash);
    TASK_CD(cd, Player, cd_player);
    TASK_CD(cd, Velocity, cd_velocity);

    if (cd_dash->enabled)
        if (cd_player->down.pressed == 1) {
            cd_velocity->vx *= 3;
            if (cd_player->up.pressed)
                cd_velocity->vy = -6;
            cd_player->down.pressed = 2;
        }
}
