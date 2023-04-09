#include "Graphics.h"
#include "EngineMantle.h"
#include <raylib.h>

#include "Components/Window.h"

void graphics_create(Box *b)
{
    box_component(b, c_window_create);
    box_archetype(b, "Graphics", "Window", NULL);
    box_entity(b, "Graphics");
}

void graphics_loop(Box *b)
{
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("MeerkatEngine", 32, 32, 20, LIGHTGRAY);

        EndDrawing();
    }
}
