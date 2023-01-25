#include "EngineCore.h"
#include "Components/Position.h"
#include "Components/Player.h"

int main()
{
    Store *s;
    Component *position_c;
    Component *player_c;
    Archetype *player_a;
    Entity *player_e;

    s = store_create();

    // Component initialization
    position_c = store_component(s, c_position_create);
    player_c   = store_component(s, c_player_create);

    // Archetype initialization
    player_a = archetype_create("Player");
    list_append(s->archetypes, player_a);

    // Entity initialization
    player_e = entity_create(player_a);
    list_append(s->entities, player_e);

    store_destroy(s);
}
