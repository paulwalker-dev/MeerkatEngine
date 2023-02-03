#include "Physics.h"

#include "Components/Position.h"

void physics_create(Box *b)
{
    box_component(b, c_position_create);
}
