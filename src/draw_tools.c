/*
** EPITECH PROJECT, 2024
** step1.c
** File description:
** main for my_paint
*/
#include "my_paint.h"
#include "macro.h"

void draw_circle_on_render_text(tool_t **tools, global_t **config,
    sfVector2f mouse_tmp)
{
    sfCircleShape_setPosition((*tools)->use_pencil, mouse_tmp);
    sfRenderTexture_drawCircleShape((*config)->paper,
        (*tools)->use_pencil, NULL);
}

void draw_rectangle_on_render_text(tool_t **tools, global_t **config,
    sfVector2f mouse_tmp)
{
    sfRectangleShape_setPosition((*tools)->use_eraser, mouse_tmp);
    sfRenderTexture_drawRectangleShape((*config)->paper,
        (*tools)->use_eraser, NULL);
}

void draw_tools(tool_t **tools, global_t **config,
    sfVector2i *mouse_pos, all_button_t **button)
{
    sfVector2f mouse_tmp = {mouse_pos->x - (*tools)->radius,
        mouse_pos->y - (*tools)->radius};

    if ((*tools)->is_active == 1) {
        if (pos_not_button(*button, *config))
            draw_circle_on_render_text(tools, config, mouse_tmp);
        sfRenderWindow_drawSprite((*config)->window, (*tools)->pencil, NULL);
    }
    if ((*tools)->is_active == 2) {
        if ((*config)->click == sfTrue)
            draw_rectangle_on_render_text(tools, config, mouse_tmp);
        sfRenderWindow_drawSprite((*config)->window, (*tools)->eraser, NULL);
    }
}

void set_and_draw_tools(all_button_t *button, global_t *config)
{
    button_management(button->button, config,
        "database/fileoptions_is_hover.png");
    button_management(button->button2, config, "database/is_over_print.png");
    button_management(button->button3, config, "database/help_is_over.png");
    sfRenderWindow_drawRectangleShape(config->window,
        button->button->rect, NULL);
    sfRenderWindow_drawRectangleShape(config->window,
        button->button2->rect, NULL);
    sfRenderWindow_drawRectangleShape(config->window,
        button->button3->rect, NULL);
}

void draw_buttons(global_t *config, all_button_t *button)
{
    sfRenderWindow_drawSprite(config->window,
        button->button->sprite, NULL);
    sfRenderWindow_drawSprite(config->window,
        button->button2->sprite, NULL);
    sfRenderWindow_drawSprite(config->window,
        button->button3->sprite, NULL);
    sfRenderWindow_drawSprite(config->window,
        button->pencilplus->sprite, NULL);
    sfRenderWindow_drawSprite(config->window,
        button->pencilminus->sprite, NULL);
    sfRenderWindow_drawSprite(config->window,
        button->colors->sprite, NULL);
}
