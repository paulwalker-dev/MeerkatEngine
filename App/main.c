#include "EngineCore.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} PositionComponent;

void *position_cd_create()
{
    PositionComponent *cd;

    cd = malloc(sizeof(PositionComponent));
    cd->x = 0;
    cd->y = 0;
    return cd;
}

typedef struct {
    char *player_name;
} PlayerComponent;

void *player_cd_create()
{
    PlayerComponent *cd;

    cd = malloc(sizeof(PlayerComponent));
    cd->player_name = "Default";
    return cd;
}

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
