#include "Graphics.h"
#include "EngineMantle.h"
#include <raylib.h>
#include <raygui.h>

#include "Components/FPS.h"
#include "Components/Window.h"

#include "Tasks/FPS.h"

void graphics_create(Box *b)
{
    box_component(b, c_fps_create);
    box_component(b, c_window_create);

    box_archetype(b, "Graphics", "Window", "FPS", NULL);
    box_entity(b, "Graphics");

    box_priority(b, 1);
    box_task(b, t_fps, "FPS", NULL);
}

void graphics_loop(Box *b)
{
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        box_update(b);
        EndDrawing();
    }
}
