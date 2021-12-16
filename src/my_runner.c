/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** screensaver_main.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"
#include "../include/my.h"

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

int is_collided(sfSprite *sprite1, sfSprite *sprite2)
{
    sfFloatRect lazer = sfSprite_getGlobalBounds(sprite1); // modifier le sfFloatrect du coup ;)
    sfFloatRect sprite = sfSprite_getGlobalBounds(sprite2);
    lazer.top = lazer.top + 16;
    lazer.width = lazer.width - 16;
    lazer.left = lazer.left + 16;
    lazer.height = lazer.height - 16;
    if (sfFloatRect_intersects(&lazer, &sprite, sfFalse))
        return (1);
    return (0);
}

play_data_t init_play_data()
{
    play_data_t play_data;

    play_data.score = 0;
    play_data.sprite = 0;
    play_data.start = 0;
    return (play_data);
}

void put_main_menu(init_sfml_t *init_sfml, game_object_t *obj,
play_data_t *play_data)
{
    inits_obj(obj, init_sfml);
    sfSprite_setTextureRect(obj[7].sprite, obj[7].rect);
    sfSprite_setPosition(obj[7].sprite, obj[7].pos);
    sfRenderWindow_drawSprite(init_sfml->window, obj[7].sprite, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyEnter))
        play_data->start = 1;
}

void put_game(init_sfml_t *init_sfml, game_object_t *obj,
play_data_t *play_data) {
     put_parallax(init_sfml, obj);
    play_data->sprite = draw_sprite_walk(init_sfml, obj, play_data->sprite);
    ++play_data->score;
    if (is_collided(obj[4].sprite, obj[3].sprite) ||
    is_collided(obj[5].sprite, obj[3].sprite) ||
    is_collided(obj[6].sprite, obj[3].sprite)) {
        play_data->start = 0;
        play_data->score = 0;
    }
    draw_lazer(init_sfml, obj);
    for (int i = 0; i < OBJ_NBR - 1; ++i)
        sfRenderWindow_drawSprite(init_sfml->window, obj[i].sprite, NULL);
    put_score(play_data->score, init_sfml);
}

void my_runner(init_sfml_t *init_sfml, sfClock *clock)
{
    game_object_t *obj = malloc(sizeof(game_object_t) * OBJ_NBR);
    play_data_t play_data = init_play_data();
    
    sfMusic *music = sfMusic_createFromFile("megalovania-x-jetpack-joyride-remix-mashup.ogg");
    sfMusic_setLoop(music, sfTrue);
    // sfMusic_play(music);
    while (sfRenderWindow_isOpen(init_sfml->window)) {
        if (play_data.start)
            put_game(init_sfml, obj, &play_data);
        else
            put_main_menu(init_sfml, obj, &play_data);
        analyse_events(init_sfml, obj, &play_data);
        function_sfml_whil(init_sfml, sfBlack);
    }
    free(obj);
}
