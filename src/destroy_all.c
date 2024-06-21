/*
** EPITECH PROJECT, 2024
** destroy_all.c
** File description:
** destroy all textures, images, window...etc
*/
#include "my_paint.h"
#include <stdlib.h>

void free_button(button_t *button1, button_t *button2, button_t *button3)
{
    sfRectangleShape_destroy(button1->rect);
    sfTexture_destroy(button1->texture);
    sfSprite_destroy(button1->sprite);
    free(button1);
    sfRectangleShape_destroy(button2->rect);
    sfTexture_destroy(button2->texture);
    sfSprite_destroy(button2->sprite);
    free(button2);
    sfRectangleShape_destroy(button3->rect);
    sfTexture_destroy(button3->texture);
    sfSprite_destroy(button3->sprite);
    free(button3);
}

void destroy_all(global_t *config, tool_t *tools)
{
    sfSprite_destroy(tools->pencil);
    sfTexture_destroy(tools->draw);
    sfTexture_destroy(tools->erase);
    sfSprite_destroy(tools->eraser);
    sfCircleShape_destroy(tools->use_pencil);
    sfRectangleShape_destroy(tools->use_eraser);
    free(tools);
    sfSprite_destroy(config->paper_sp);
    sfRenderTexture_destroy(config->paper);
    sfText_destroy(config->help);
    sfFont_destroy(config->help_font);
}

void destroy_menu(menu_t *menu)
{
    sfRectangleShape_destroy(menu->rect);
    sfSprite_destroy(menu->sprite);
    sfTexture_destroy(menu->texture);
    sfSprite_destroy(menu->pencil);
    sfTexture_destroy(menu->draw);
    free(menu->paths);
    free(menu);
}
