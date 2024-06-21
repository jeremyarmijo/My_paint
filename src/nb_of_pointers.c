/*
** EPITECH PROJECT, 2024
** step1.c
** File description:
** main for my_paint
*/
#include "my_paint.h"
#include "macro.h"


int nb_of_pointers(menu_t **str1)
{
    menu_t *str = *str1;
    int i = 0;

    for (; str != 0; str = str->next) {
        i++;
    }
    return i;
}
