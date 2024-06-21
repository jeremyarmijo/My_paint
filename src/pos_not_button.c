/*
** EPITECH PROJECT, 2024
** step1.c
** File description:
** main for my_paint
*/
#include "my_paint.h"
#include "macro.h"

int pos_not_button(all_button_t *button, global_t *config)
{
    if (config->click == sfTrue
            && !is_hover_in_stuct(button->menu2, config)
            && !is_hover_in_stuct(button->menu3, config)
            && !is_hover_in_stuct(button->menu, config)
            && !is_hover(button->button, config)
            && !is_hover(button->button2, config)
            && !is_hover(button->button3, config))
        return 1;
    return 0;
}
