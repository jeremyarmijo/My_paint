/*
** EPITECH PROJECT, 2024
** step1.c
** File description:
** main for my_paint
*/
#include "my_paint.h"
#include "macro.h"

void set_menu2(all_button_t *button, global_t *config, tool_t *tools)
{
    int nb_rtrn = 0;

    if (button->button2->is_active == 1) {
        nb_rtrn = print_menu(&button->menu2, &config, &button->button2, 1);
        set_sprite(button->button2, "database/pencil_menu_is_hover.png");
        if (nb_rtrn == 0) {
            sfRenderWindow_setMouseCursorVisible((config->window), sfFalse);
            tools->is_active = 1;
        }
        if (nb_rtrn == 1) {
            sfRenderWindow_setMouseCursorVisible((config->window), sfFalse);
            tools->is_active = 2;
        }
        if (nb_rtrn == 2) {
            sfRenderWindow_setMouseCursorVisible((config->window), sfTrue);
            tools->is_active = 0;
        }
    }
}

void set_menu1(all_button_t *button, global_t *config, tool_t **tools)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(button->colors->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(config->window);

    if (config->click == sfTrue &&
        sfFloatRect_contains(&hitbox,
            (float)mouse_pos.x, (float)mouse_pos.y)) {
        sfCircleShape_setFillColor((*tools)->use_pencil, sfRed);
    }
    if (button->button->is_active == 1) {
        set_sprite(button->button, "database/menu_file_is_hover.png");
        print_menu(&button->menu, &config, &button->button, 0);
    }
}

void set_sizes_tools(all_button_t *button, global_t *config, tool_t **tools)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(button->pencilplus->sprite);
    sfFloatRect hitbox2 =
        sfSprite_getGlobalBounds(button->pencilminus->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(config->window);

    if (config->click == sfTrue &&
        sfFloatRect_contains(&hitbox,
            (float)mouse_pos.x, (float)mouse_pos.y)) {
            (*tools)->radius += 1;
            sfCircleShape_setRadius((*tools)->use_pencil, (*tools)->radius);
            sfRectangleShape_setSize((*tools)->use_eraser,
                (sfVector2f) {(*tools)->radius, (*tools)->radius});
    } else if (config->click == sfTrue
        && (sfFloatRect_contains(&hitbox2,
            (float)mouse_pos.x, (float)mouse_pos.y))) {
            (*tools)->radius -= (*tools)->radius <= 0 ? 0 : 1;
            sfCircleShape_setRadius((*tools)->use_pencil, (*tools)->radius);
            sfRectangleShape_setSize((*tools)->use_eraser,
                (sfVector2f){(*tools)->radius, (*tools)->radius});
    }
}

void set_menu3(all_button_t *button, global_t *config, tool_t **tools)
{
    set_sizes_tools(button, config, tools);
    if (button->button3->is_active == 1) {
        set_sprite(button->button3, "database/help_is_over.png");
            print_menu(&button->menu3, &config, &button->button3, 2);
    }
}
