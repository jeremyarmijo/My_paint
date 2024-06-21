/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main function for my_paints
*/
#include "my_paint.h"
#include "macro.h"

button_t *init_sprites(button_t *button,
    char const *path_sprites, float scale, int pos)
{
    button->sprite = sfSprite_create();
    if (!button->sprite)
        return NULL;
    button->texture = sfTexture_createFromFile(path_sprites, NULL);
    if (!button->sprite)
        return NULL;
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_scale(button->sprite, (sfVector2f) {scale, scale});
    sfSprite_setPosition(button->sprite, (sfVector2f) {50 * pos, 0});
    return button;
}

void init_nb_button(all_button_t **all_button, button_t *button,
    button_t *button2, button_t *button3)
{
    button = init_sprites(button, "database/fileoptionclose.png", 0.09, 0);
    button2 = init_sprites(button2, "database/pencil2.png", 0.09, 1);
    button3 = init_sprites(button3, "database/help.png", 0.09, 2);
    (*all_button)->button = button;
    (*all_button)->button->nb_button = 3;
    (*all_button)->button2 = button2;
    (*all_button)->button2->nb_button = 3;
    (*all_button)->button3 = button3;
    (*all_button)->button3->nb_button = 2;
    sfSprite_setPosition((*all_button)->pencilplus->sprite,
        (sfVector2f) {50 * (3.7), -10});
    sfSprite_setScale((*all_button)->colors->sprite,
        (sfVector2f) {0.18, 0.18});
}

all_button_t *init_all_button(void)
{
    all_button_t *all_button = malloc(sizeof(all_button_t));
    button_t *button = init_button(0);
    button_t *button2 = init_button(1);
    button_t *button3 = init_button(2);
    button_t *minus = init_button(4);
    button_t *plus = init_button(5);
    button_t *colors = init_button(7);

    minus = init_sprites(minus, "database/button_minus.png", 0.09, 5);
    plus = init_sprites(plus, "database/buplus.png", 0.14, 4);
    colors = init_sprites(colors, "database/colors.png", 1, 7);
    all_button->colors = colors;
    all_button->pencilminus = minus;
    all_button->pencilplus = plus;
    sfRectangleShape_setSize(all_button->pencilminus->rect, button->size);
    sfRectangleShape_setPosition(button->rect, button->position);
    sfRectangleShape_setOutlineColor(button->rect, sfBlack);
    init_nb_button(&all_button, button, button2, button3);
    return all_button;
}
