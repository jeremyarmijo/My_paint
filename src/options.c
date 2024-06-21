/*
** EPITECH PROJECT, 2024
** step1.c
** File description:
** main for my_paint
*/
#include "my_paint.h"
#include "macro.h"

static void save_to_file(global_t **config)
{
    sfImage *save = sfImage_create(WINDOW_WIDTH, WINDOW_LENGTH);

    save = sfTexture_copyToImage((*config)->paper_text);
    sfImage_saveToFile(save, "save_files/paint.jpg");
    sfImage_destroy(save);
}

static void load_file(global_t **config)
{
    sfImage *load = sfImage_createFromFile("save_files/paint.jpg");
    sfTexture *load_texture = sfTexture_createFromImage(load, NULL);
    sfSprite *load_sprite = sfSprite_create();

    sfSprite_setTexture(load_sprite, load_texture, sfTrue);
    sfRenderTexture_drawSprite((*config)->paper, load_sprite, NULL);
    sfImage_destroy(load);
    sfTexture_destroy(load_texture);
    sfSprite_destroy(load_sprite);
}

int options_menu1(global_t **config, int i)
{
    if (i == 0) {
        sfRenderTexture_clear((*config)->paper, sfWhite);
        (*config)->paper_text = sfRenderTexture_getTexture((*config)->paper);
        return 0;
    }
    if (i == 1) {
        load_file(config);
        return 1;
    }
    if (i == 2) {
        save_to_file(config);
        return 2;
    }
    return -1;
}

int options_menu2(int i)
{
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    if (i == 2) {
        return 2;
    }
    return -1;
}

int options_menu3(global_t **config, int i)
{
    if (i == 0) {
        if ((*config)->print_help == sfFalse)
            (*config)->print_help = sfTrue;
        else
            (*config)->print_help = sfFalse;
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    return -1;
}
