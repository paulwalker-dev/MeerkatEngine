#include "Player.h"
#include <stdlib.h>

void *cd_player_create()
{
    PlayerComponent *cd;

    cd = malloc(sizeof(PlayerComponent));
    cd->player_name = "Default";
    return cd;
}

Component *c_player_create()
{
    Component *c;

    c = component_create("Player");
    c->data_init = cd_player_create;
    return c;
}
