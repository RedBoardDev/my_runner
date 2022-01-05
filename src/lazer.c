/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** lazer.c
*/

#include "../include/my_runner.h"

void set_lazer_infini(game_object_t *obj, init_sfml_t *init_sfml)
{
    int rand_bool = my_rand(0,8);
    sfVector2f origin = {246 / 2, 78 / 2};

    sfSprite_setOrigin(obj->sprite, origin);
    obj->pos.x -= obj->speed * init_sfml->speed_coef;
    if (obj->pos.x <= -100) {
        obj->pos.y = my_rand(95, HEIGHT - 200);
        obj->pos.x = WIDTH + my_rand(300,2920);
        if (rand_bool > 3)
            sfSprite_rotate(obj->sprite, 90);
    }
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, obj->pos);
}

void set_pos_lazer_maps(game_object_t *obj, bool *rotate, int ligne, char c)
{
    if (obj[ligne + 4].pos.x <= -100) {
        if (c == '2') {
            rotate = false;
            sfSprite_rotate(obj[ligne + 4].sprite, 90);
        }
        if (obj[ligne + 4].pos.x <= -100)
            obj[ligne + 4].pos.x = WIDTH + 100;
        if (ligne == 0)
            obj[ligne + 4].pos.y = my_rand(95, 340);
        else if (ligne == 1)
            obj[ligne + 4].pos.y = my_rand(360, 710);
        else if (ligne == 2)
            obj[ligne + 4].pos.y = my_rand(740, 950);
    }
}

void set_lazer_maps(game_object_t *obj, init_sfml_t *init_sfml, int ligne)
{
    char c;
    bool rotate = false;
    sfVector2f origin = {246 / 2, 78 / 2};

    sfSprite_setOrigin(obj[ligne + 4].sprite, origin);
    obj[ligne + 4].pos.x -= obj[ligne + 4].speed * init_sfml->speed_coef;
    c = init_sfml->map[ligne][obj[4].jump];
    obj[4].jump += 1;
    if (c != ' ') {
        if (obj[4].jump >= 162)
            obj[4].jump = 0;
        if (sfClock_getElapsedTime(obj[ligne + 4].clock).microseconds >=
        1000000) {
            sfClock_restart(obj[ligne + 4].clock);
            set_pos_lazer_maps(obj, &rotate, ligne, c);
        }
    }
    if (rotate)
        sfSprite_rotate(obj[ligne + 4].sprite, -90);
    sfSprite_setTextureRect(obj[ligne + 4].sprite, obj[ligne + 4].rect);
    sfSprite_setPosition(obj[ligne + 4].sprite, obj[ligne + 4].pos);
}

void move_lazer(game_object_t *obj)
{
    if (sfClock_getElapsedTime(obj->clock).microseconds >= 140000) {
        obj->rect.left = 5760 + 249;
        if (sfClock_getElapsedTime(obj->clock).microseconds >= 140000 * 2)
            sfClock_restart(obj->clock);
    } else
        obj->rect.left = 5760;
}

void draw_lazer(init_sfml_t *init_sfml, game_object_t *obj)
{

    move_lazer(&obj[7]);

    if (init_sfml->infini)
        for (int i = 0; i < 3; ++i) {
            set_lazer_infini(&obj[i + 4], init_sfml);
            
        }
    else {
        for (int i = 0; i < 3; ++i)
            set_lazer_maps(obj, init_sfml, i);
    }
}
