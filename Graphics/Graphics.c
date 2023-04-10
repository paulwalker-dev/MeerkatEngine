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
    TASK_E(b->s->entities, Graphics, e_graphics);
    TASK_CD(e_graphics->data, Window, cd_window);

    Rectangle rect;

    rect.width = 96;
    rect.height = 32;
    while (!cd_window->should_close) {
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        box_update(b);

        rect.x = GetRenderWidth() - rect.width - 8;
        rect.y = GetRenderHeight() - rect.height - 8;
        cd_window->should_close |= GuiButton(rect, GuiIconText(ICON_EXIT, "Close"));

        EndDrawing();
        cd_window->should_close |= WindowShouldClose();
    }
}
