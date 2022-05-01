/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_strtok
*/

#include <stddef.h>
#include "my_base.h"
#include <math.h>

static char *strtok_tmp = NULL;

char *strtoked(char *str, const char *delims, int len)
{
    char *offset;
    int tmp = 0;

    if (str == NULL && strtok_tmp == NULL)
        return (NULL);
    if (str != NULL && strtok_tmp == NULL)
        strtok_tmp = str;
    offset = strtok_tmp;
    while (tmp != len)
        for (tmp = 0; tmp < len; ++tmp)
            if (*offset == delims[tmp]) {
                ++offset;
                break;
            }
    strtok_tmp = offset;
    return (offset);
}

char *our_strtok(char *str, const char *delims)
{
    int tmp = 0;
    int len = my_strlen(delims);
    char *offset = strtoked(str, delims, len);

    if (*strtok_tmp == '\0') {
        strtok_tmp = NULL;
        return (NULL);
    }
    while (*strtok_tmp != '\0') {
        for (tmp = 0; tmp < len; ++tmp)
            if (*strtok_tmp == delims[tmp]) {
                *strtok_tmp = '\0';
                break;
            }
        ++strtok_tmp;
        if (tmp < len)
            break;
    }
    return (offset);
}

float str_to_float(char *str)
{
    float entier = (float)str_to_int(str);
    float virgule = 0;
    int neg = 1;

    if (entier == 0 && str[0] == '-') {
        ++str;
        neg *= -1;
    }
    str += (int_len(entier) + (entier < 0 ? 2 : 1));
    for (int i = 0; IS_NUM(str[i]); ++i)
        virgule += ((str[i] - 48) * pow(10, - i - 1));

    return (entier < 0 ? (entier - virgule) * neg : (entier + virgule) * neg);
}