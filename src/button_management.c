/*
** EPITECH PROJECT, 2024
** step1.c
** File description:
** main for my_paint
*/
#include "my_paint.h"
#include "macro.h"

void button_management(button_t *button, global_t *config, char *path_sprite)
{
    if (is_button_pressed(button, config)) {
        button->is_active = 1;
    } else if (is_hover(button, config)) {
        button->texture = sfTexture_createFromFile(path_sprite, NULL);
        sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    }
}
