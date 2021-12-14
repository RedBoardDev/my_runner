/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** screensaver_main.c
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

void put_parallax(init_sfml_t *init_sfml, game_object_t *obj)
{
    for (int i = 0; i < 3; ++i) {
        obj[i].rect.left += obj[i].speed;
        if (obj[i].rect.left >= 1920 * 2)
            obj[i].rect.left = 0;
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
        sfSprite_setPosition(obj[i].sprite, obj[i].pos);
    }
}

int draw_sprite_walk(init_sfml_t *init_sfml, game_object_t *obj, int sprite)
{
    int nb = 3;
    int bool = 0;

    if (sfKeyboard_isKeyPressed(sfKeySpace) && obj[3].pos.y >= 0) {
        obj[3].pos_incr = -10;
        bool = 1;
    }
    obj[3].pos.y += obj[3].pos_incr;
    if (obj[3].pos.y < 820)
        obj[3].pos_incr = 10;
    if (obj[3].pos.y >= 820)
        obj[3].pos_incr = 0;
    if (sfClock_getElapsedTime(obj[3].clock).microseconds >= 100000) {
        sprite = sprite < 3 ? ++sprite : 0;
        sfClock_restart(obj[3].clock);
    }
    if (obj[nb].pos.y >= 820) {
        switch (sprite) {
        case 0: //1er
            obj[nb].rect.top = 12;
            obj[nb].rect.left = 5765;
            obj[nb].rect.width = 116;
            obj[nb].rect.height = 162;
            break;
        case 1: //2ieme
            obj[nb].rect.top = 12;
            obj[nb].rect.left = 5895;
            obj[nb].rect.width = 118;
            obj[nb].rect.height = 168;
            break;
        case 2: //3ième
            obj[nb].rect.top = 12;
            obj[nb].rect.left = 6031;
            obj[nb].rect.width = 116;
            obj[nb].rect.height = 168;
            break;
        case 3: //4ième
            obj[nb].rect.top = 12;
            obj[nb].rect.left = 6158;
            obj[nb].rect.width = 124;
            obj[nb].rect.height = 162;
            break;
        default:
            break;
        }
    } else if (bool) {
            obj[nb].rect.top = 12;
            obj[nb].rect.left = 6424;
            obj[nb].rect.width = 124;
            obj[nb].rect.height = 186;
    } else {
            obj[nb].rect.top = 12;
            obj[nb].rect.left = 6300;
            obj[nb].rect.width = 110;
            obj[nb].rect.height = 166;
    }
    sfSprite_setTextureRect(obj[nb].sprite, obj[nb].rect);
    sfSprite_setPosition(obj[nb].sprite, obj[nb].pos);
    return (sprite);
}

void put_score(int score, init_sfml_t *init_sfml)
{
    sfText *text = sfText_create();
    sfVector2f vector = {100, 100};
    sfFont *font  = sfFont_createFromFile("test.ttf");

    sfText_setFont(text, font);
    sfText_setString(text, my_itoa(score));
    sfText_setCharacterSize(text, 24);
    sfText_setPosition(text, vector);
    sfText_setColor(text, sfRed);
    sfRenderWindow_drawText(init_sfml->window, text, NULL);
}

int is_collided(sfSprite *sprite1, sfSprite *sprite2)
{
    sfFloatRect lazer = sfSprite_getGlobalBounds(sprite1);
    sfFloatRect sprite = sfSprite_getGlobalBounds(sprite2);
    if (sfFloatRect_intersects(&lazer, &sprite, sfFalse))
        return (1);
    return (0);
}

void my_runner(init_sfml_t *init_sfml, sfClock *clock)
{
    game_object_t *obj = malloc(sizeof(game_object_t) * OBJ_NBR);
    int sprite = 0;
    int score = 0;
    inits_obj(obj, init_sfml);
    while (sfRenderWindow_isOpen(init_sfml->window)) {
        put_parallax(init_sfml, obj);
        sprite = draw_sprite_walk(init_sfml, obj, sprite);
        analyse_events(init_sfml->window, init_sfml, obj);
        ++score;
        if (is_collided(obj[4].sprite, obj[3].sprite))
            score = 1;
        draw_lazer(init_sfml, obj);
        for (int i = 0; i < OBJ_NBR; ++i)
            sfRenderWindow_drawSprite(init_sfml->window, obj[i].sprite, NULL);
        put_score(score, init_sfml);
        function_sfml_whil(init_sfml, sfBlack);
    }
    free(obj);
}
