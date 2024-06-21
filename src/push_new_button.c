/*
** EPITECH PROJECT, 2024
** step1.c
** File description:
** main for my_paint
*/
#include "my_paint.h"
#include "macro.h"

void init_button_sprite(menu_t **bu, int x, int y)
{
    sfSprite_setTexture((*bu)->sprite, (*bu)->texture, sfTrue);
    sfSprite_scale((*bu)->sprite, (sfVector2f) {0.09, 0.09});
    sfSprite_setPosition((*bu)->sprite, (sfVector2f) {50 * x, 50 * y});
    sfRectangleShape_setSize((*bu)->rect, (*bu)->size);
    sfRectangleShape_setPosition((*bu)->rect, (*bu)->position);
    sfRectangleShape_setOutlineThickness((*bu)->rect, 0);
}

menu_t *push_new_button(menu_t **menu, int x, int y, path_sprites_t *paths)
{
    menu_t *current = *menu;
    sfVector2f position = {50 * x, 50 * y};
    sfVector2f size = {50, 50};
    menu_t *bu = malloc(sizeof(menu_t));

    for (; current->next != NULL; current = current->next);
    bu->radius = 50.00;
    bu->rect = sfRectangleShape_create();
    bu->position = position;
    bu->size = size;
    bu->next = NULL;
    current->next = bu;
    bu->paths = paths;
    bu->sprite = sfSprite_create();
    bu->texture = sfTexture_createFromFile(paths->basic, NULL);
    init_button_sprite(&bu, x, y);
    return *menu;
}
