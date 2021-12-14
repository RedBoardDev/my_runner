/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** lazer.c
*/

#include "../include/my_runner.h"

void set_lazer(game_object_t *obj)
{
    int bool = rand() % 8;
    sfVector2f origin = {246 / 2, 78 / 2};

    sfSprite_setOrigin(obj->sprite, origin);
    obj->pos.x -= obj->speed;
    if (obj->pos.x <= - 100) {
        obj->pos.y = rand() % ((HEIGHT - 200) - 86 + 1) + 86;
        obj->pos.x = WIDTH + 100;
        if (bool > 3)
            sfSprite_rotate(obj->sprite, 90);
    }
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, obj->pos);
}

void draw_lazer(init_sfml_t *init_sfml, game_object_t *obj)
{

    for (int i = 0; i <= 1; ++i) {
        set_lazer(&obj[i + 4]);
    }
}