#include "Player.h"
#include <stdlib.h>

char *player_states[] = {
    PLAYER_SOLID,
    PLAYER_LIQUID,
    PLAYER_NONE
};

void *cd_player_create()
{
    CD_INIT(Player, cd);
    cd->next = 0;
    cd->state = player_states[cd->next++];
    cd->old_state = "";
    return cd;
}

Component *c_player_create()
COMPONENT(Player, cd_player_create);
