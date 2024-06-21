/*
** EPITECH PROJECT, 2024
** init
** File description:
** sprites
*/
#include "my_paint.h"
#include "macro.h"

void set_options_sprites_plus(global_t **config,
    float scale, float x, float y)
{
    SP_1 = sfSprite_create();
    TP_1 = sfTexture_createFromFile("database/button_plus.png", NULL);
    sfSprite_setTexture((*config)->extra.splus,
        (*config)->extra.tplus, sfTrue);
    sfSprite_scale((*config)->extra.splus,
        (sfVector2f) {scale, scale});
    sfSprite_setPosition((*config)->extra.splus,
        (sfVector2f) {x, y});
}

void set_options_sprites_minus(global_t **config,
    float scale, float x, float y)
{
    SM_1 = sfSprite_create();
    TM_1 = sfTexture_createFromFile("database/minus_b.png", NULL);
    sfSprite_setTexture((*config)->extra.sminus,
        (*config)->extra.tminus, sfTrue);
    sfSprite_scale((*config)->extra.sminus,
        (sfVector2f) {scale, scale});
    sfSprite_setPosition((*config)->extra.sminus,
        (sfVector2f) {x, y});
}
