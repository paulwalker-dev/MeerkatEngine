#include "Gravity.h"
#include "EngineMantle.h"

#include "../Components/Velocity.h"

void t_gravity(Store *s, List *cd, List *e)
{
    TASK_CD(cd, Velocity, cd_velocity);
    
    cd_velocity->vy++;
    if (cd_velocity->vy > 8)
        cd_velocity->vy = 8;
}
