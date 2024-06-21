/*
** EPITECH PROJECT, 2024
** init_game.c
** File description:
** initialize game status
*/
#include "my_paint.h"
#include "macro.h"
#include <stdlib.h>

void set_init_game(button_t *button, tool_t *tools)
{
    sfVector2f scale = {0.1, 0.1};
    sfVector2f origin = {50, 510};

    sfSprite_setOrigin(tools->pencil, origin);
    sfSprite_setScale(tools->pencil, scale);
    sfRectangleShape_setSize(button->rect, button->size);
    sfRectangleShape_setPosition(button->rect, button->position);
    sfRectangleShape_setOutlineColor(button->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
}

button_t *init_button(int coef)
{
    sfVector2f position = {50 * coef, 0};
    sfVector2f size = {50, 50};
    button_t *bu = malloc(sizeof(button_t));

    if (bu == NULL)
        return NULL;
    bu->is_active = 0;
    bu->radius = 30;
    bu->rect = sfRectangleShape_create();
    bu->position = position;
    bu->size = size;
    bu->state = NONE;
    return bu;
}

static sfCircleShape *create_circle(float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, sfBlack);
    return circle;
}

static sfRectangleShape *create_rectangle(float radius)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfVector2f size = {radius, radius};

    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, sfWhite);
    return rectangle;
}

tool_t *init_tools(void)
{
    tool_t *tools = malloc(sizeof(tool_t));

    if (tools == NULL)
        return NULL;
    tools->pencil = sfSprite_create();
    tools->eraser = sfSprite_create();
    tools->radius = 30;
    tools->use_pencil = create_circle(tools->radius);
    tools->use_eraser = create_rectangle(tools->radius);
    if (!tools->pencil || !tools->eraser)
        return NULL;
    tools->draw = sfTexture_createFromFile("database/pencil.png", NULL);
    tools->erase = sfTexture_createFromFile("database/eraser.png", NULL);
    if (!tools->draw || !tools->erase)
        return NULL;
    sfSprite_setTexture(tools->pencil, tools->draw, sfTrue);
    sfSprite_setTexture(tools->eraser, tools->erase, sfTrue);
    sfSprite_scale(tools->eraser, (sfVector2f) {0.04, 0.04});
    return tools;
}

sfRenderWindow *init_window(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_LENGTH, BIT_PER_PIXEL};
    sfRenderWindow* window = sfRenderWindow_create(mode, "my_paints",
        sfResize | sfClose, NULL);

    return window;
}

global_t *init_game_status(void)
{
    global_t *config = malloc(sizeof(global_t));

    if (config == NULL)
        return NULL;
    config->paper = sfRenderTexture_create(WINDOW_WIDTH, WINDOW_LENGTH,
        sfFalse);
    sfRenderTexture_clear(config->paper, sfWhite);
    config->paper_text = sfRenderTexture_getTexture(config->paper);
    config->paper_sp = sfSprite_create();
    sfSprite_setTexture(config->paper_sp, config->paper_text, sfTrue);
    config->window = init_window();
    config->click = sfFalse;
    config->help = sfText_create();
    config->help_font = sfFont_createFromFile("database/Arial.ttf");
    sfText_setString(config->help, HELP);
    sfText_setFont(config->help, config->help_font);
    sfText_setPosition(config->help, (sfVector2f){0, 500});
    sfText_setColor(config->help, sfRed);
    config->print_help = sfFalse;
    return config;
}
