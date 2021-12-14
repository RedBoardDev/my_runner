/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** events.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"

int analyse_events(sfRenderWindow *window, init_sfml_t *init_sfml, game_object_t *obj)
{
    sfEvent event;
    int r = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
    }
    return (r);
}
