/*
** EPITECH PROJECT, 2021
** libmy_base
** File description:
** array1
*/

#include "my_base.h"
#include <stdlib.h>

int my_arrlen(char **arr)
{
    int res = 0;

    if (!arr)
        return (-1);
    while (*arr) {
        ++res;
        ++arr;
    }
    return (res);
}

char **my_arrdup(char **arr)
{
    char **n_arr = malloc(sizeof(char *) * (my_arrlen(arr) + 1));

    if (!n_arr)
        return (NULL);
    n_arr[my_arrlen(arr)] = NULL;
    for (int i = 0; arr[i]; ++i) {
        n_arr[i] = my_strdup(arr[i]);
        if (!n_arr[i])
            return (NULL);
    }
    return (n_arr);
}

void free_arr(char ** const arr)
{
    for (int i = 0; arr[i] != NULL; ++i)
        free(arr[i]);
    free(arr);
}

int where_str_on_arr(char const * const str, char const * const *arr)
{
    for (int i = 0; arr[i]; ++i)
        if (!my_strcmp(str, arr[i]))
            return (i);
    return (-1);
}

void alpha_sort_arr(char **arr)
{
    for (int i = 0; arr[i + 1]; ++i)
        for (int j = i + 1; arr[j]; ++j)
            if (my_strcomp_alpha(arr[i], arr[j]) > 0)
                swap_str(&arr[i], &arr[j]);
}