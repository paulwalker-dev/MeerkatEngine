#include "Collision.h"
#include "EngineMantle.h"

#include "../Components/Position.h"
#include "../Components/Velocity.h"

void t_no_void(Store *s, List *cd, List *e)
{
    TASK_CD(cd, Position, cd_position);
    TASK_CD(cd, Velocity, cd_velocity);

    if (cd_position->y >= 100) {
        cd_position->y = 100;
        cd_velocity->vy = 0;
    }
}
