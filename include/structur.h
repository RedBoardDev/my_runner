/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** structur.h
*/

#include "my_runner.h"

#ifndef STRUCTURE_H_
    #define STRUCTURE_H_

typedef struct init_sfml_s {
    sfRenderWindow *window;
    sfUint8 *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
} init_sfml_t;

typedef struct game_object_s {
    int enumer;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    float speed;
    int pos_incr;
    sfClock *clock;
} game_object_t;


#endif
