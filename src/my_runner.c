/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** screensaver_main.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"
#include "../include/my.h"

void is_dead(play_data_t *play_data, sound_ambiant_t *sound_ambiant)
{
    sfMusic *die = sfMusic_createFromFile("ressources/sounds/die_player.ogg");

    sfMusic_stop(sound_ambiant->main);
    sfMusic_play(die);
    play_data->start = 0;
}

void put_game(init_sfml_t *init_sfml, game_object_t *obj,
play_data_t *play_data, sound_ambiant_t *sound_ambiant) {
    move_parallax(init_sfml, obj);
    draw_sprite_walk(init_sfml, obj, play_data, sound_ambiant);
    play_data->score += init_sfml->speed_coef - 1;
    if (is_collided_sprite(obj))
        is_dead(play_data, sound_ambiant);
    draw_lazer(init_sfml, obj);
    sfSprite_setPosition(obj[8].sprite, obj[8].pos);
    move_scientifist(init_sfml, &obj[8], obj[2].speed);
    manage_missile(init_sfml, obj);
    manage_draw_sprite(init_sfml, obj);
    put_score(play_data->score, init_sfml);
}

void set_sounds(sound_ambiant_t *sound_ambiant)
{
    sound_ambiant->main =
    sfMusic_createFromFile("ressources/sounds/jetpack-remix.ogg");
    sound_ambiant->walk =
    sfMusic_createFromFile("ressources/sounds/walk.ogg");
    sound_ambiant->rocket =
    sfMusic_createFromFile("ressources/sounds/rocket.ogg");
    sfMusic_play(sound_ambiant->walk);
    sfMusic_play(sound_ambiant->rocket);
    sfMusic_setLoop(sound_ambiant->main, sfTrue);
    sfMusic_setLoop(sound_ambiant->walk, sfTrue);
    sfMusic_setLoop(sound_ambiant->rocket, sfTrue);
    sfMusic_setVolume(sound_ambiant->main, 70);
    sfMusic_setVolume(sound_ambiant->walk, 0);
    sfMusic_setVolume(sound_ambiant->rocket, 0);
}

void my_runner(init_sfml_t *init_sfml, sfClock *clock)
{
    game_object_t *obj = malloc(sizeof(game_object_t) * OBJ_NBR);
    play_data_t play_data = init_play_data();
    sound_ambiant_t sound_ambiant;

    set_sounds(&sound_ambiant);
    while (sfRenderWindow_isOpen(init_sfml->window)) {
        if (sfClock_getElapsedTime(init_sfml->clock).microseconds >= 1000) {
        sfClock_restart(init_sfml->clock);
            play_data.start ? put_game(init_sfml, obj, &play_data,
            &sound_ambiant) : put_main_menu(init_sfml, obj, &play_data,
            &sound_ambiant);
            analyse_events(init_sfml, obj, &play_data);
            function_sfml_whil(init_sfml, sfBlack);
        }
    }
    free(obj);
}
