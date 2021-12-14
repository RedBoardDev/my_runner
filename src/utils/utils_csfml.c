/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** utils_csfml.c
*/

#include "../../include/my_runner.h"
#include "../../include/structur.h"

sfUint8 *framebuffer_create(int w, int h)
{
    return (malloc(sizeof(sfUint8) * (w * h * 4)));
}

void function_sfml_whil(init_sfml_t *init_sfml, sfColor c)
{
    // sfRenderWindow_clear(init_sfml->window, c);
    // sfSprite_setTexture(init_sfml->sprite, init_sfml->texture, sfFalse);
    // sfTexture_updateFromPixels(init_sfml->texture, init_sfml->framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_display(init_sfml->window);
}
