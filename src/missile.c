/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** missile.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"
#include "../include/my.h"

void sprite_missile(game_object_t *obj)
{
    if (get_timeClock(obj->game_clock.missile_sprite) >= 60000) {
        sfClock_restart(obj->game_clock.missile_sprite);
        if (obj[9].rect.left <= 5760 + (3 * 120)) {
            obj[9].rect.left += 120;
        } else
            obj[9].rect.left = 5760;
        sfSprite_setTextureRect(obj[9].sprite, obj[9].rect);
        sfSprite_setPosition(obj[9].sprite, obj[9].pos);
    }
}

void manage_missile(init_sfml_t *init_sfml, game_object_t *obj)
{
    sprite_missile(obj);
    if (get_timeClock(obj[9].clock) >= 5000000/*my_rand(8000000, 50000000)*/) {
        sfClock_restart(obj[9].clock);
        obj[9].pos.x = WIDTH - 200;
    }
    if (obj[9].pos.x >= -200)
        obj[9].pos.x -= 8 * init_sfml->speed_coef;
    else
        obj[9].pos.y = my_rand(10, HEIGHT - 10);
}
