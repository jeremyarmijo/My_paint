/*
** EPITECH PROJECT, 2024
** step1.c
** File description:
** main for my_paint
*/
#include "my_paint.h"
#include "macro.h"

void init_button_menu(int x, int y, menu_t **bu)
{
    sfSprite_setTexture((*bu)->sprite, (*bu)->texture, sfTrue);
    sfSprite_scale((*bu)->sprite, (sfVector2f) {0.09, 0.09});
    sfSprite_setPosition((*bu)->sprite, (sfVector2f) {50 * x, 50 * y});
    sfRectangleShape_setSize((*bu)->rect, (*bu)->size);
    sfRectangleShape_setPosition((*bu)->rect, (*bu)->position);
    sfRectangleShape_setFillColor((*bu)->rect, sfBlue);
    sfRectangleShape_setOutlineThickness((*bu)->rect, 1);
}

menu_t *init_menu(int x, int y, char *str1, char *str2)
{
    sfVector2f position = {50 * x, 50 * y};
    sfVector2f size = {50, 50};
    menu_t *bu = malloc(sizeof(menu_t));
    path_sprites_t *paths = malloc(sizeof(path_sprites_t));

    bu->radius = 50.00;
    bu->rect = sfRectangleShape_create();
    bu->position = position;
    bu->size = size;
    bu->next = NULL;
    paths->basic = duplicate_string(str1);
    paths->is_hover = duplicate_string(str2);
    bu->paths = paths;
    bu->sprite = sfSprite_create();
    bu->texture = sfTexture_createFromFile(paths->basic, NULL);
    init_button_menu(x, y, &bu);
    return bu;
}
