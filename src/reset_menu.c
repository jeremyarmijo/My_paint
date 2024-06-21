/*
** EPITECH PROJECT, 2024
** step1.c
** File description:
** main for my_paint
*/
#include "my_paint.h"
#include "macro.h"

sfBool reset_menu(sfVector2i *mouse_pos, button_t *button)
{
    sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfMouse_isButtonPressed(sfMouseLeft) && button->is_active == 1) {
        if (!sfFloatRect_contains(&hitbox, mouse_pos->x, mouse_pos->y))
            button->is_active = 0;
        if (sfFloatRect_contains(&hitbox, mouse_pos->x, mouse_pos->y))
            button->is_active = 0;
        return sfTrue;
    }
    return sfFalse;
}
