/*
** EPITECH PROJECT, 2021
** libmy_base
** File description:
** str_to_array.c
*/

#include "my_base.h"
#include <stdlib.h>
#include <stdbool.h>

bool is_delim(char c, char const *delim)
{
    for (int i = 0; delim[i]; ++i)
        if (c == delim[i])
            return (true);
    return (false);
}

int args_nb(char const *str, char const *delim)
{
    int nb_args = 0;

    while (*str) {
        if (!is_delim(*str, delim) &&
        (is_delim(*(str + 1), delim) || !*(str + 1)))
            nb_args += 1;
        ++str;
    }
    return (nb_args);
}

int arg_len(char const *str, char const *delim)
{
    int len_arg = 0;

    while (!is_delim(*str, delim) && *str) {
        ++str;
        ++len_arg;
    }
    return (len_arg);
}

char **str_to_arr(char const *str, char const *delim)
{
    int nb_args = args_nb(str, delim);
    int len_arg;
    char **res = malloc(sizeof(char *) * (nb_args + 1));

    for (int i = 0; i < nb_args; ++i) {
        len_arg = arg_len(str, delim);
        res[i] = malloc(sizeof(char) * (len_arg + 1));
        my_strncpy(str, res[i], len_arg);
        res[i][len_arg] = 0;
        str += len_arg;
        while (is_delim(*str, delim) && *str)
            ++str;
    }
    res[nb_args] = NULL;
    return (res);
}
