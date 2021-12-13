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

int draw_sprite_walk(init_sfml_t *init_sfml, game_object_t *obj, int sprite,
sfClock *clock)
{
    int nb = 3;
    if (sfClock_getElapsedTime(clock).microseconds <= 100000)
        return (sprite);
    sfClock_restart(clock);
    sprite = sprite < 2 ? ++sprite : 0;
    obj[nb].pos.x = WIDTH / 3;
    if (obj[nb].pos.y > HEIGHT / 1.24 - 2)
        switch (sprite) {
        case 0:
            obj[nb].rect.top = 0;
            obj[nb].rect.left = 5760;
            obj[nb].rect.width = 84;
            obj[nb].rect.height = 178;
            break;
        case 1:
            obj[nb].rect.top = 0;
            obj[nb].rect.left = 5855;
            obj[nb].rect.width = 84;
            obj[nb].rect.height = 178;
            break;
        case 2:
            obj[nb].rect.top = 0;
            obj[nb].rect.left = 5940;
            obj[nb].rect.width = 84;
            obj[nb].rect.height = 178;
            break;
        default:
            break;
        }
    else {
        obj[nb].rect.top = 0;
        obj[nb].rect.left = 6035;
        obj[nb].rect.width = 84;
        obj[nb].rect.height = 178;
    }
    sfSprite_setTextureRect(obj[nb].sprite, obj[nb].rect);
    sfSprite_setPosition(obj[nb].sprite, obj[nb].pos);
    return (sprite);
}

void put_score(int score, init_sfml_t *init_sfml)
{
    sfText *text = sfText_create();
    sfVector2f vector = {50, 50};

    sfText_setString(text, "Hello SFML");
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, vector);
    sfText_setColor(text, sfRed);
    sfRenderWindow_drawText(init_sfml->window, text, sfFalse);
}

void my_runner(init_sfml_t *init_sfml, sfClock *clock)
{
    game_object_t *obj = malloc(sizeof(game_object_t) * OBJ_NBR);
    int sprite = 0;
    int score = 0;

    inits_obj(obj, init_sfml);
    while (sfRenderWindow_isOpen(init_sfml->window)) {
        put_parallax(init_sfml, obj);
        sprite = draw_sprite_walk(init_sfml, obj, sprite, clock);

        if (analyse_events(init_sfml->window, init_sfml, obj))
            obj[3].pos_incr = -20;
        else if (obj[3].pos.y < HEIGHT / 1.24 - 1 && obj[3].pos_incr == 0)
            obj[3].pos_incr = 6;
        else
            obj[3].pos_incr = 0;
        obj[3].pos.y += obj[3].pos_incr;
                
        for (int i = 0; i < OBJ_NBR; ++i)
            sfRenderWindow_drawSprite(init_sfml->window, obj[i].sprite, NULL);
        put_score(score, init_sfml);
        function_sfml_whil(init_sfml, sfBlack);
    }
}
