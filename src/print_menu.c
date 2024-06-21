/*
** EPITECH PROJECT, 2024
** step1.c
** File description:
** main for my_paint
*/
#include "my_paint.h"
#include "macro.h"

sfBool is_button_menu_pressed(sfRectangleShape *rect,
    global_t *config, button_t *button)
{
    sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(rect);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(config->window);

    if (sfMouse_isButtonPressed(sfMouseLeft) && button->is_active == 1) {
        if (!sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y))
        return sfFalse;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y))
            return sfTrue;
    }
    return sfFalse;
}

void menu_button_management(menu_t *str, global_t *config, button_t *button)
{
    sfRectangleShape_setFillColor(str->rect, sfWhite);
    sfTexture_destroy(str->texture);
    str->texture = sfTexture_createFromFile(str->paths->basic, NULL);
    sfSprite_setTexture(str->sprite, str->texture, sfTrue);
    if (is_button_pressed_in_struct(str, config)) {
        button->radius = 10;
    } else if (is_hover_in_stuct(str, config)) {
        sfTexture_destroy(str->texture);
        str->texture = sfTexture_createFromFile(str->paths->is_hover, NULL);
        sfSprite_setTexture(str->sprite, str->texture, sfTrue);
        sfRectangleShape_setFillColor(str->rect, sfBlack);
    }
    sfRenderWindow_drawRectangleShape(config->window, str->rect, NULL);
    sfRenderWindow_drawSprite(config->window, str->sprite, NULL);
}

int print_menu(menu_t **menu, global_t **config, button_t **button, int nb)
{
    menu_t *str = *menu;

    for (int i = 0; str != 0; str = str->next) {
        menu_button_management(str, *config, *button);
        if (is_button_menu_pressed(str->rect, *config, *button) && nb == 0) {
            return options_menu1(config, i);
        }
        if (is_button_menu_pressed(str->rect, *config, *button) && nb == 1) {
            return options_menu2(i);
        }
        if (is_button_menu_pressed(str->rect, *config, *button) && nb == 2) {
            return options_menu3(config, i);
        }
        i++;
    }
    return -1;
}
