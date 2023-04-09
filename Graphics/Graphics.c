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
    int hue;

    hue = 0;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(ColorFromHSV(++hue % 360, 1, 1));
        box_update(b);
        EndDrawing();
    }
}
