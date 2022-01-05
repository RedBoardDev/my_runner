/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** missile.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"
#include "../include/my.h"

void set_missile(game_object_t *obj, bool pos_x)
{
    obj->rect.top = 500;
    obj->rect.left = 1920 * 3;
    obj->rect.width = 125;
    obj->rect.height = 90;
    if (pos_x)
        obj->pos.x = WIDTH + 100;

}

void manage_missile(init_sfml_t *init_sfml, game_object_t *obj)
{
    if (sfClock_getElapsedTime(obj->clock).microseconds >= 50000) {
        sfClock_restart(obj->clock);
        if (obj->rect.left <= 5760 + (5 * 140)) {
            obj->rect.left += 140;
        } else
            obj->rect.left = 5760;
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        sfSprite_setPosition(obj->sprite, obj->pos);
    }
}
