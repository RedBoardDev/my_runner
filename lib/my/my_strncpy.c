/*
** EPITECH PROJECT, 2021
** MY_STRNCPY
** File description:
** MY_STRNCPY
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int  n)
{
    int i = 0;
    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        ++i;
    }
    if (i == my_strlen(src)) {
        dest[i] = '\0';
    }
    return dest;
}
