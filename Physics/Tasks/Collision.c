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
    cd_physics->floored = 0;
    
    l = component_list_create(s, "Physics", "Position", "Size", NULL);
    for (i = 0; i < e->length; ++i) {
        object = list_get(e, i);
        data = entity_data_get(object);
        if (task_filter(data, l)) {
            list_free(data);
            continue;
        };

        TASK_CD(data, Physics, cd_t_physics);
        TASK_CD(data, Position, cd_t_position);
        TASK_CD(data, Size, cd_t_size);

        if (cd_physics->id == cd_t_physics->id) {
            list_free(data);
            continue;
        }

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
            if (x + w - cd_velocity->vx - 1 < tx) {
                x = tx - w;
                cd_velocity->vx = 0;
            } else if (tx + tw - 1 < x - cd_velocity->vx) {
                x = tx + tw;
                cd_velocity->vx = 0;
            } else if (y - cd_velocity->vy < ty) {
                y = ty - h;
                cd_velocity->vy = 0;
                cd_physics->floored = 1;
            } else {
                y = ty + th;
                cd_velocity->vy = 0;
            }
        }

        cd_position->x = x;
        cd_position->y = y;

        list_free(data);
    }

    list_free(l);
}
