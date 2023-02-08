#include "Physics.h"

#include "Components/Physics.h"
#include "Components/Position.h"
#include "Components/Size.h"
#include "Components/Velocity.h"

#include "Tasks/Collision.h"
#include "Tasks/Gravity.h"
#include "Tasks/Velocity.h"

void physics_create(Box *b)
{
    box_component(b, c_physics_create);
    box_component(b, c_position_create);
    box_component(b, c_size_create);
    box_component(b, c_velocity_create);

    box_task(b, t_move, "Position", "Velocity", NULL);
    box_task(b, t_gravity, "Physics", "Velocity", NULL);
    box_task(b, t_collision, "Physics", "Position", "Size", "Velocity", NULL);
}
