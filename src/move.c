/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** move.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"

int move_parallax(init_sfml_t *init_sfml, game_object_t *obj)
{
    for (int i = 0; i < 3; ++i) {
        obj[i].rect.left += obj[i].speed * init_sfml->speed_coef;
        if (obj[i].rect.left > 3840)
            obj[i].rect.left = 0;
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
        sfSprite_setPosition(obj[i].sprite, obj[i].pos);
    }
    init_sfml->speed_coef <= 2 ? (init_sfml->speed_coef += 0.0004) : 0;
}

void move_scientifist(init_sfml_t *init_sfml, game_object_t *obj, float speed)
{
    obj->pos.x = obj->pos.x - speed;
}
