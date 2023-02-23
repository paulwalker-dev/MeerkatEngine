#include "Gravity.h"
#include "EngineMantle.h"

#include "../Components/Physics.h"
#include "../Components/Velocity.h"

void t_gravity(Store *s, List *cd, List *e)
{
    TASK_CD(cd, Physics, cd_physics);
    TASK_CD(cd, Velocity, cd_velocity);
    
    if (cd_physics->stationary)
        return;

    cd_velocity->vy += 0.5;
    if (cd_velocity->vy < -8)
        cd_velocity->vy = -8;
    if (cd_velocity->vy > 8)
        cd_velocity->vy = 8;
}
