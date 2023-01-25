#include "Player.h"
#include <stdlib.h>

void *player_cd_create()
{
    PlayerComponent *cd;

    cd = malloc(sizeof(PlayerComponent));
    cd->player_name = "Default";
    return cd;
}
