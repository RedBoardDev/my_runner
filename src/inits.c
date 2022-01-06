/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** inits.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"

play_data_t init_play_data(void)
{
    play_data_t play_data;

    play_data.score = 0;
    play_data.sprite = 0;
    play_data.start = 0;
    return (play_data);
}
