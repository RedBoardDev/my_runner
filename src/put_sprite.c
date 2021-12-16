/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** put_sprite.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"
#include "../include/my.h"

int draw_sprite_walk(init_sfml_t *init_sfml, game_object_t *obj, int sprite)
{
    int nb = 3;
    int bool = 0;

    if (obj[3].jump == 1) {
        bool = 1;
        if (obj[3].pos.y >= 0)
            obj[3].pos_incr = -10;
        else
            obj[3].pos_incr = 0;
    }
    obj[3].pos.y += obj[3]  .pos_incr;
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
            // sfSoundBuffer *buffer;
            // sfSoundBuffer_createFromFile("walk.ogg");
            // sfSound *sound = sfSound_create();
            // sfSound_setBuffer(sound, buffer);
            // sfSound_play(sound);
            // sfSound_destroy(sound);
            // sfSoundBuffer_destroy(buffer);

            obj[nb].rect.top = 12;
            obj[nb].rect.left = 6300;
            obj[nb].rect.width = 110;
            obj[nb].rect.height = 166;
    }
    sfSprite_setTextureRect(obj[nb].sprite, obj[nb].rect);
    sfSprite_setPosition(obj[nb].sprite, obj[nb].pos);
    return (sprite);
}
