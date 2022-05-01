/*
** EPITECH PROJECT, 2021
** libmy_base
** File description:
** nbr_tests
*/

#include "my_base.h"
#include <stdbool.h>

unsigned int int_len(int nb)
{
    unsigned int res = 0;

    if (nb == 0)
        return (1);
    while (nb) {
        nb /= 10;
        ++res;
    }
    return (res);
}

bool is_int(char const *str)
{
    for (unsigned int i = 0; i < my_strlen(str); ++i) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return (false);
        if (str[i] == '-' && i != 0)
            return (false);
    }
    return (true);
}

bool is_float(char const *str)
{
    int point = 0;

    for (unsigned int i = 0; i < my_strlen(str); ++i) {
        if ((str[i] < '0' || str[i] > '9') && (str[i] != '-' || str[i] != '.'))
            return (false);
        if ((str[i] == '-' && i != 0) || (str[i] == '.' &&
        ((str[i + 1] < '0' || str[i + 1] > '9') || point == 1)))
            return (false);
        else
            point = 1;
    }
    return (true);
}