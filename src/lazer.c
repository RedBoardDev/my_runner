/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** lazer.c
*/

#include "../include/my_runner.h"

void set_lazer(game_object_t *obj)
{
    int bool = my_rand(0,8);
    sfVector2f origin = {246 / 2, 78 / 2};

    sfSprite_setOrigin(obj->sprite, origin);
    obj->pos.x -= obj->speed;
    if (obj->pos.x <= - 100) {
        obj->pos.y = my_rand(86, HEIGHT - 200);
        obj->pos.x = WIDTH + my_rand(300,1920);
        if (bool > 3)
            sfSprite_rotate(obj->sprite, 90);
    }
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, obj->pos);
}

void draw_lazer(init_sfml_t *init_sfml, game_object_t *obj)
{
    for (int i = 0; i < 3; ++i) {
        set_lazer(&obj[i + 4]);
    }
}
