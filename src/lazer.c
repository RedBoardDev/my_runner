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

    printf("cc\n");
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

void settings_lazer_maps(game_object_t *obj, init_sfml_t *init_sfml,
bool rotate, int ligne)
{
    sfVector2f origin = {246 / 2, 78 / 2};

    sfSprite_setOrigin(obj->sprite, origin);
    if (obj->pos.x <= - 100) {
        if (ligne == 0)
            obj->pos.y = my_rand(95, 360);
        else if (ligne == 1)
            obj->pos.y = my_rand(360, 720);
        else if (ligne == 2)
            obj->pos.y = my_rand(720, 1080);
        obj->pos.x = WIDTH + 150;
    }
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, obj->pos);
}

void set_lazer_maps(game_object_t *obj, init_sfml_t *init_sfml, int ligne)
{
    char c;
    int j;
    sfVector2f origin = {246 / 2, 78 / 2};
    sfSprite_setOrigin(obj[ligne + 4].sprite, origin);
    obj[ligne + 4].pos.x -= obj[ligne + 4].speed * init_sfml->speed_coef;
    c = init_sfml->map[ligne][obj[4].jump];
    printf("%c ", c);
    if (obj[ligne + 4].pos.x <= -100) {
        obj[ligne + 4].pos.y = my_rand(95, HEIGHT - 200);
        obj[ligne + 4].pos.x = WIDTH + my_rand(300,2920);
    }
    sfSprite_setTextureRect(obj[ligne + 4].sprite, obj[ligne + 4].rect);
    sfSprite_setPosition(obj[ligne + 4].sprite, obj[ligne + 4].pos);

}

void draw_lazer(init_sfml_t *init_sfml, game_object_t *obj)
{
    if (init_sfml->infini)
        for (int i = 0; i < 3; ++i)
            set_lazer_infini(&obj[i + 4], init_sfml);
    else {
        for (int i = 0; i < 3; ++i)
            set_lazer_maps(obj, init_sfml, i);
        obj[4].jump += 1;
        if (obj[4].jump >= 162)
            obj[4].jump = 0;
    }
}
