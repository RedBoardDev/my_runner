/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** collision.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"

int is_collided_sprite(game_object_t *obj)
{
    sfFloatRect lazer;
    sfFloatRect sprite;

    for (int i = 0; i < 3; ++i) {
        lazer = sfSprite_getGlobalBounds(obj[i + 4].sprite);
        sprite = sfSprite_getGlobalBounds(obj[3].sprite);
        lazer.top = lazer.top + 16;
        lazer.width = lazer.width - 16;
        lazer.left = lazer.left + 16;
        lazer.height = lazer.height - 16;

        sprite.top = sprite.top + 25;
        sprite.width = sprite.width - 14;
        sprite.left = sprite.left + 6;
        sprite.height = sprite.height - 14;
        if (sfFloatRect_intersects(&lazer, &sprite, sfFalse))
            return (1);
    }
    return (0);
}
