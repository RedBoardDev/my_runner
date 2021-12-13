/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** main.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"
#include "../include/my.h"

sfRenderWindow *create_window(char *name) {
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, name,
    sfFullscreen | sfClose, NULL);

    sfWindow_setFramerateLimit((sfWindow *)window, 60);
    return (window);
}

int main(int avc, char **avg)
{
    init_sfml_t init_sfml;
    sfClock *clock = sfClock_create();

    init_sfml.window = create_window("MAIS OUI BIEN SUR");
    init_sfml.framebuffer = framebuffer_create(WIDTH, HEIGHT);
    init_sfml.texture = sfTexture_createFromFile("img/texture.png", NULL);
    sfWindow_setFramerateLimit(init_sfml.window, 60);
    if (!init_sfml.window || !init_sfml.framebuffer)
        return (84);
    my_runner(&init_sfml, clock);
    free(init_sfml.framebuffer);
    sfTexture_destroy(init_sfml.texture);
    sfRenderWindow_destroy(init_sfml.window);
    return (0);
}
