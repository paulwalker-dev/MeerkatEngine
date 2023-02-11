#include "Player.h"
#include <stdlib.h>

void *cd_player_create()
{
    CD_INIT(Player, cd);
    return cd;
}

Component *c_player_create()
COMPONENT(Player, cd_player_create);
