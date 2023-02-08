#include "Velocity.h"
#include "EngineMantle.h"

#include "../Components/Position.h"
#include "../Components/Velocity.h"

void t_move(Store *s, List *cd, List *e) {
    TASK_CD(cd, Position, cd_position);
    TASK_CD(cd, Velocity, cd_velocity);
    float vx = cd_velocity->vx;

    if (vx < 0)
        vx += 0.5;
    if (vx > 0)
        vx -= 0.5;

    if (vx < -16)
        vx = -16;
    if (vx > 16)
        vx = 16;

    cd_velocity->vx = vx;
    cd_position->x += cd_velocity->vx;
    cd_position->y += cd_velocity->vy;
}
