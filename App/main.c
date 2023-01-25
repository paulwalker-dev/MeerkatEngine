#include "EngineCore.h"

#include "Components/Position.h"
#include "Components/Player.h"

int main()
{
    Component *position_c;
    Component *player_c;
    Archetype *player_a;
    Entity *player_e;

    // Component initialization
    position_c = component_create("Position");
    position_c->data_init = position_cd_create;

    player_c = component_create("Player");
    player_c->data_init = player_cd_create;

    // Archetype initialization
    player_a = archetype_create("Player");

    // Entity initialization
    player_e = entity_create(player_a);

    // Entity deallocation
    entity_destroy(player_e);

    // Archetype deallocation
    archetype_destroy(player_a);

    // Component deallocation
    component_destroy(position_c);
    component_destroy(player_c);
}
