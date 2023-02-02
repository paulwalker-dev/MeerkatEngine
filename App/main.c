#include "EngineMantle.h"
#include "EngineGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <unistd.h>

#include "Components/Player.h"

#include "Tasks/Player.h"

void t_info_run(List *cd, List *e)
{
    TASK_CD(cd, GraphicsPosition, cd_position);
    
    printf("Position: { x: %d, y: %d }\n",
           cd_position->x,
           cd_position->y);
}

int main(int argv, char *argc[])
{
    Box *b;
    Entity *e_player1;
    Entity *e_player2;

    // Ensure assets can be accessed via relative paths
    chdir(dirname(argc[0]));

    b = box_create();

    graphics_create(b);

    box_component(b, c_player_create);
    box_archetype(b, "Player", "Player", "GraphicsImage", "GraphicsPosition", "GraphicsSize", NULL);

    e_player1 = box_entity(b, "Player");
    TASK_CD(e_player1->data, GraphicsImage, cd_image);
    cd_image->filename = "assets/grass_top.qoi";
    
    /*
    e_player2 = box_entity(b, "Player");
    TASK_CD(e_player2->data, Player, cd_player);
    cd_player->up.key    = SDLK_UP;
    cd_player->down.key  = SDLK_DOWN;
    cd_player->left.key  = SDLK_LEFT;
    cd_player->right.key = SDLK_RIGHT;
    */

    box_task(b, t_player_move, "Player", NULL);

    graphics_loop(b);
    box_destroy(b);
}
