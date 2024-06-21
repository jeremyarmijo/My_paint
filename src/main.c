/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main function for my_paints
*/
#include "my_paint.h"
#include "macro.h"

path_sprites_t *init_paths(char *str1, char *str2)
{
    path_sprites_t *paths = malloc(sizeof(path_sprites_t));

    paths->basic = duplicate_string(str1);
    paths->is_hover = duplicate_string(str2);
    return paths;
}

all_button_t *init_menus(all_button_t *all_button)
{
    all_button->menu = init_menu(0, 1,
        "database/new_file.png", "database/hover_new_fil.png");
    push_new_button(&all_button->menu, 0, 2,
        init_paths("database/open_file.png", "database/hover_open_file.png"));
    push_new_button(&all_button->menu, 0, 3,
        init_paths("database/save_file2.png", "database/hover_save.png"));
    all_button->menu2 = init_menu(1, 1,
        "database/pencil_select.png", "database/pencil_hover.png");
    push_new_button(&all_button->menu2, 1, 2, init_paths
        ("database/eraser_option.png", "database/eraser_select.png"));
    push_new_button(&all_button->menu2, 1, 3,
        init_paths("database/normal_mode.png", "database/cursor_yellow.png"));
    all_button->menu3 = init_menu(2, 1,
        "database/help_select.png", "database/help_option.png");
    return all_button;
}

int main(void)
{
    all_button_t *all_button = init_all_button();
    global_t *config = init_game_status();
    tool_t *tools = init_tools();

    all_button = init_menus(all_button);
    if (config == NULL || !config->window || tools == NULL)
        return EXIT_WITH_ERROR;
    sfRenderWindow_setFramerateLimit(config->window, MAX_FRAME);
    set_init_game(all_button->button, tools);
    set_init_game(all_button->button2, tools);
    set_init_game(all_button->button3, tools);
    while (sfRenderWindow_isOpen(config->window))
        loop_window(&config, &all_button, &tools);
    sfRenderWindow_destroy(config->window);
    destroy_all(config, tools);
    free_button(all_button->button, all_button->button2, all_button->button3);
    return EXIT_WITH_SUCCESS;
}
