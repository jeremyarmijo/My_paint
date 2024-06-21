/*
** EPITECH PROJECT, 2024
** handle_button.c
** File description:
** handle button color when stat change
*/
#include "my_paint.h"

sfBool is_button_pressed(button_t *button, global_t *config)
{
    sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(button->rect);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(config->window);

    if (sfMouse_isButtonPressed(sfMouseLeft) && button->is_active == 1) {
        if (!sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y))
            button->is_active = 0;
        return sfFalse;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y))
            return sfTrue;
    }
    return sfFalse;
}

sfBool is_hover(button_t *button, global_t *config)
{
    sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(button->rect);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(config->window);

    if (sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y))
        return sfTrue;
    return sfFalse;
}
