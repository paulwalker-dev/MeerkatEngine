#include "Liquid.h"
#include "EngineMantle.h"
#include "EnginePhysics.h"

#include "../Components/Input.h"

void t_player_liquid(Store *s, List *cd, List *e)
{
    TASK_E(e, AppController, e_controller);
    TASK_CD(e_controller->data, Input, cd_input);
    TASK_CD(cd, Physics, cd_physics);
    TASK_CD(cd, Velocity, cd_velocity);
    int jump;
    float vx;

    jump = input_key_status(cd_input, "jump");
    if (cd_physics->floored && jump) {
        cd_velocity->vy = -4;
    }

    vx = cd_velocity->vx;
    if (input_key_status(cd_input, "left"))
        vx = fminf(-3.5, vx);
    if (input_key_status(cd_input, "right"))
        vx = fmaxf(3.5, vx);
    cd_velocity->vx = vx;
}
