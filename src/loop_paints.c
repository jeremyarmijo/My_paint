/*
** EPITECH PROJECT, 2024
** step1.c
** File description:
** main for my_paint
*/
#include "my_paint.h"
#include "macro.h"

void set_sprite(button_t *button, char *path_sprite)
{
    sfRectangleShape_setFillColor(button->rect, sfWhite);
    sfTexture_destroy(button->texture);
    button->texture = sfTexture_createFromFile(path_sprite, NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
}

void set_pos_tools_button_default(all_button_t *button, tool_t *tools,
    sfVector2i *mouse_pos)
{
    sfVector2f mouse_true = {(*mouse_pos).x, (*mouse_pos).y};

    sfSprite_setPosition(tools->pencil, mouse_true);
    sfSprite_setPosition(tools->eraser,
        (sfVector2f) {mouse_pos->x, mouse_pos->y - 50});
    set_sprite(button->button, "database/fileoptionclose.png");
    set_sprite(button->button2, "database/pencil2.png");
    set_sprite(button->button3, "database/help.png");
    sfRectangleShape_setFillColor(button->button3->rect, sfWhite);
}

void check_event_type(global_t *config)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        config->click = sfTrue;
    else
        config->click = sfFalse;
}

void print_help(global_t **config)
{
    if ((*config)->print_help == sfTrue)
        sfRenderWindow_drawText((*config)->window, (*config)->help, NULL);
}

void loop_window(global_t **config, all_button_t **button, tool_t **tools)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow((*config)->window);

    while (sfRenderWindow_pollEvent((*config)->window, &(*config)->event)){
        if ((*config)->event.type == sfEvtClosed)
            sfRenderWindow_close((*config)->window);
        check_event_type(*config);
    }
    sfRenderWindow_clear((*config)->window, sfBlack);
    sfRenderWindow_drawSprite((*config)->window, (*config)->paper_sp, NULL);
    sfRenderTexture_display((*config)->paper);
    set_pos_tools_button_default(*button, *tools, &mouse_pos);
    set_menu1(*button, *config, tools);
    set_menu2(*button, *config, *tools);
    set_menu3(*button, *config, tools);
    set_and_draw_tools(*button, *config);
    draw_buttons(*config, *button);
    draw_tools(tools, config, &mouse_pos, button);
    print_help(config);
    sfRenderWindow_display((*config)->window);
}
