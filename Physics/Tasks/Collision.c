#include "Collision.h"
#include "EngineMantle.h"

#include "../Components/Physics.h"
#include "../Components/Position.h"
#include "../Components/Size.h"
#include "../Components/Velocity.h"

void t_collision(Store *s, List *cd, List *e)
{
    TASK_CD(cd, Physics, cd_physics);
    TASK_CD(cd, Position, cd_position);
    TASK_CD(cd, Size, cd_size);
    TASK_CD(cd, Velocity, cd_velocity);
    Entity *object;
    List *data;
    List *l;
    int x, y;
    int w, h;
    int i;

    if (cd_physics->stationary)
        return;

    x = cd_position->x;
    y = cd_position->y;
    w = cd_size->w;
    h = cd_size->h;
    
    l = component_list_create(s, "Physics", "Position", "Size", NULL);
    for (i = 0; i < e->length; ++i) {
        object = list_get(e, i);
        data = entity_data_get(object);
        if (task_filter(data, l)) continue;

        TASK_CD(data, Physics, cd_t_physics);
        TASK_CD(data, Position, cd_t_position);
        TASK_CD(data, Size, cd_t_size);

        if (cd_physics->id == cd_t_physics->id)
            continue;

        int tx, ty;
        int tw, th;

        tx = cd_t_position->x;
        ty = cd_t_position->y;
        tw = cd_t_size->w;
        th = cd_t_size->h;

        if (
            x < tx + tw &&
            x + w > tx &&
            y < ty + th &&
            h + y > ty
        ) {
            cd_position->y = ty - h;
            cd_velocity->vy = 0;
        }
    }

    list_free(l);
}
