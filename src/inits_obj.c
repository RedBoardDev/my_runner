/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** inits_obj.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"
#include "../include/my.h"

void inits_paralax(game_object_t *obj, init_sfml_t *init_sfml)
{
    obj[0].rect.top = 0;
    obj[0].rect.left = 0;
    obj[0].rect.width = 1920;
    obj[0].rect.height = 1080;
    obj[0].speed = 6;

    obj[1].rect.top = 1080;
    obj[1].rect.left = 0;
    obj[1].rect.width = 1920;
    obj[1].rect.height = 1080;
    obj[1].speed = 10;

    obj[2].rect.top = 2160;
    obj[2].rect.left = 0;
    obj[2].rect.width = 1920;
    obj[2].rect.height = 1080;
    obj[2].speed = 14;
}

void inits_player(game_object_t *obj, init_sfml_t *init_sfml)
{
    obj[3].rect.top = 0;
    obj[3].rect.left = 5760;
    obj[3].rect.width = 84;
    obj[3].rect.height = 178;
    obj[3].speed = 0;
    obj[3].sprite = sfSprite_create();
    obj[3].pos.x = WIDTH / 3;
    obj[3].pos.y = HEIGHT / 1.24;

    // obj[4].rect.top = 0;
    // obj[4].rect.left = 5855;
    // obj[4].rect.width = 84;
    // obj[4].rect.height = 178;
    // obj[4].speed = 0;
    // obj[4].sprite = sfSprite_create();
    // obj[4].pos.x = WIDTH / 3;
    // obj[4].pos.y = HEIGHT / 1.24;

    // obj[5].rect.top = 0;
    // obj[5].rect.left = 5940;
    // obj[5].rect.width = 84;
    // obj[5].rect.height = 178;
    // obj[5].speed = 0;
    // obj[5].sprite = sfSprite_create();
    // obj[5].pos.x = WIDTH / 3;
    // obj[5].pos.y = HEIGHT / 1.24;

    // obj[6].rect.top = 0;
    // obj[6].rect.left = 6035;
    // obj[6].rect.width = 84;
    // obj[6].rect.height = 178;
    // obj[6].speed = 0;
    // obj[6].sprite = sfSprite_create();
    // obj[6].pos.x = WIDTH / 3;
    // obj[6].pos.y = HEIGHT / 1.24;
}

void inits_lazer(game_object_t *obj, init_sfml_t *init_sfml)
{
    // obj[7].rect.top = 200;
    // obj[7].rect.left = 5760;
    // obj[7].rect.width = 248;
    // obj[7].rect.height = 76;
    // obj[7].speed = 0;
    // obj[7].sprite = sfSprite_create();
    // obj[7].pos.x = 0;
    // obj[7].pos.y = 0;

}

void inits_obj(game_object_t *obj, init_sfml_t *init_sfml)
{
    inits_paralax(obj, init_sfml);
    inits_player(obj, init_sfml);
    inits_lazer(obj, init_sfml);
    for (int i = 0; i < OBJ_NBR; ++i) {
        obj[i].sprite = sfSprite_create();
        sfSprite_setTexture(obj[i].sprite, init_sfml->texture, sfFalse);
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
    }
}
