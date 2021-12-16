/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** inits_obj.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"
#include "../include/my.h"

game_object_t *create_object(sfVector2f pos, sfIntRect rect, sfTexture *texture)
{
    game_object_t *game_object;

    game_object->sprite = sfSprite_create();
    game_object->pos = pos;
    game_object->rect = rect;
}

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
    obj[3].rect.top = 12;
    obj[3].rect.left = 5765;
    obj[3].rect.width = 116;
    obj[3].rect.height = 162;
    obj[3].speed = 0;
    obj[3].sprite = sfSprite_create();
    obj[3].pos.x = WIDTH / 3;
    obj[3].pos.y = 820;
    obj[3].pos_incr = 0;
    obj[3].clock = sfClock_create();
    obj[3].jump = 0;
}

void inits_lazer(game_object_t *obj, init_sfml_t *init_sfml)
{
    obj[4].rect.top = 383;
    obj[4].rect.left = 5760;
    obj[4].rect.width = 246;
    obj[4].rect.height = 78;
    obj[4].speed = 14;
    obj[4].sprite = sfSprite_create();
    obj[4].pos.x = WIDTH + 100;
    obj[4].pos.y = HEIGHT - 200;

    obj[5].rect.top = 383;
    obj[5].rect.left = 5760;
    obj[5].rect.width = 246;
    obj[5].rect.height = 78;
    obj[5].speed = 14;
    obj[5].sprite = sfSprite_create();
    obj[5].pos.x = WIDTH + 100;
    obj[5].pos.y = HEIGHT - 200;

    obj[6].rect.top = 383;
    obj[6].rect.left = 5760;
    obj[6].rect.width = 246;
    obj[6].rect.height = 78;
    obj[6].speed = 14;
    obj[6].sprite = sfSprite_create();
    obj[6].pos.x = WIDTH + 100;
    obj[6].pos.y = HEIGHT - 200;
}

void start_menu(game_object_t *obj, init_sfml_t *init_sfml)
{
    obj[7].rect.top = 2160;
    obj[7].rect.left = 1920*3;
    obj[7].rect.width = 1920;
    obj[7].rect.height = 1080;
    obj[7].speed = 0;
}

void inits_obj(game_object_t *obj, init_sfml_t *init_sfml)
{
    inits_paralax(obj, init_sfml);
    inits_player(obj, init_sfml);
    inits_lazer(obj, init_sfml);
    start_menu(obj, init_sfml);
    for (int i = 0; i < OBJ_NBR; ++i) {
        obj[i].sprite = sfSprite_create();
        sfSprite_setTexture(obj[i].sprite, init_sfml->texture, sfFalse);
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
    }
}
