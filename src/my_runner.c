/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** screensaver_main.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"
#include "../include/my.h"

int put_parallax(init_sfml_t *init_sfml, game_object_t *obj)
{
    for (int i = 0; i < 3; ++i) {
        obj[i].rect.left += obj[i].speed * init_sfml->speed_coef;
        if (obj[i].rect.left > 3840)
            obj[i].rect.left = 0;
        sfSprite_setTextureRect(obj[i].sprite, obj[i].rect);
        sfSprite_setPosition(obj[i].sprite, obj[i].pos);
    }
    init_sfml->speed_coef <= 2 ? (init_sfml->speed_coef += 0.0004) : 0;
}

void put_main_menu(init_sfml_t *init_sfml, game_object_t *obj,
play_data_t *play_data, sound_ambiant_t *sound_ambiant)
{
    sfMusic_setVolume(sound_ambiant->rocket, 0);
    sfMusic_setVolume(sound_ambiant->walk, 0);
    inits_obj(obj, init_sfml);
    sfSprite_setTextureRect(obj[7].sprite, obj[7].rect);
    sfSprite_setPosition(obj[7].sprite, obj[7].pos);
    sfRenderWindow_drawSprite(init_sfml->window, obj[7].sprite, NULL);
    put_score(play_data->score, init_sfml);
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        play_data->start = 1;
        play_data->score = 0;
        sfMusic_play(sound_ambiant->main);
    }
    init_sfml->speed_coef = 1;
}

void move_scientifist(init_sfml_t *init_sfml, game_object_t *obj, float speed)
{
    obj->pos.x = obj->pos.x - speed;
}

void is_dead(play_data_t *play_data, sound_ambiant_t *sound_ambiant)
{
    sfMusic *die = sfMusic_createFromFile("include/sounds/die_player.ogg");

    sfMusic_stop(sound_ambiant->main);
    sfMusic_play(die);
    play_data->start = 0;
}

void manage_draw_sprite(init_sfml_t *init_sfml, game_object_t *obj)
{
    for (int i = 0; i < OBJ_NBR; ++i)
        sfRenderWindow_drawSprite(init_sfml->window, obj[i].sprite, NULL);
    for (int i = 0; i < 3; ++i) // 0 - 2
        sfRenderWindow_drawSprite(init_sfml->window, obj[i].sprite, NULL);
    sfRenderWindow_drawSprite(init_sfml->window, obj[8].sprite, NULL);
    for (int i = 3; i < 7; ++i) // 3 - 6
        sfRenderWindow_drawSprite(init_sfml->window, obj[i].sprite, NULL);
    sfRenderWindow_drawSprite(init_sfml->window, obj[9].sprite, NULL);
}

void put_game(init_sfml_t *init_sfml, game_object_t *obj,
play_data_t *play_data, sound_ambiant_t *sound_ambiant) {
    put_parallax(init_sfml, obj);
    draw_sprite_walk(init_sfml, obj, play_data, sound_ambiant);
    play_data->score += init_sfml->speed_coef - 1;
    if (is_collided_sprite(obj))
        is_dead(play_data, sound_ambiant);
    draw_lazer(init_sfml, obj);
    sfSprite_setPosition(obj[8].sprite, obj[8].pos);
    move_scientifist(init_sfml, &obj[8], obj[2].speed);
    manage_missile(init_sfml, &obj[9]);
    manage_draw_sprite(init_sfml, obj);
    put_score(play_data->score, init_sfml);
}

void my_runner(init_sfml_t *init_sfml, sfClock *clock)
{
    game_object_t *obj = malloc(sizeof(game_object_t) * OBJ_NBR);
    play_data_t play_data = init_play_data();
    sound_ambiant_t sound_ambiant;

    sound_ambiant.main = sfMusic_createFromFile("include/sounds/jetpack-remix.ogg");
    sound_ambiant.walk = sfMusic_createFromFile("include/sounds/walk.ogg");
    sound_ambiant.rocket = sfMusic_createFromFile("include/sounds/rocket.ogg");

    sfMusic_play(sound_ambiant.walk);
    sfMusic_play(sound_ambiant.rocket);
    sfMusic_setLoop(sound_ambiant.main, sfTrue);
    sfMusic_setLoop(sound_ambiant.walk, sfTrue);
    sfMusic_setLoop(sound_ambiant.rocket, sfTrue);
    sfMusic_setVolume(sound_ambiant.main, 70);
    sfMusic_setVolume(sound_ambiant.walk, 0);
    sfMusic_setVolume(sound_ambiant.rocket, 0);
    while (sfRenderWindow_isOpen(init_sfml->window)) {
        if (sfClock_getElapsedTime(init_sfml->clock).microseconds >= 1000) {
        sfClock_restart(init_sfml->clock);
            if (play_data.start)
                put_game(init_sfml, obj, &play_data, &sound_ambiant);
            else
                put_main_menu(init_sfml, obj, &play_data, &sound_ambiant);
            analyse_events(init_sfml, obj, &play_data);
            function_sfml_whil(init_sfml, sfBlack);
        }
    }
    free(obj);
}
