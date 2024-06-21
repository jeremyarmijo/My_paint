/*
** EPITECH PROJECT, 2024
** step1.c
** File description:
** main for my_paint
*/
#include "my_paint.h"
#include "macro.h"

sfBool is_hover_in_stuct(menu_t *button, global_t *config)
{
    sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(button->rect);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(config->window);

    if (sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y))
        return sfTrue;
    return sfFalse;
}

sfBool is_button_pressed_in_struct(menu_t *button, global_t *config)
{
    sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(button->rect);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(config->window);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y))
            return sfTrue;
    }
    return sfFalse;
}
