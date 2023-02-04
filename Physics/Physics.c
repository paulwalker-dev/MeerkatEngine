#include "Physics.h"

#include "Components/Position.h"
#include "Components/Velocity.h"

#include "Tasks/Collision.h"
#include "Tasks/Gravity.h"

void physics_create(Box *b)
{
    box_component(b, c_position_create);
    box_component(b, c_velocity_create);

    box_task(b, t_gravity, "Velocity", NULL);
    box_task(b, t_no_void, "Position", "Velocity", NULL);
}
