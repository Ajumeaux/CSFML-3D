/*
** EPITECH PROJECT, 2021
** libmy_base
** File description:
** array2
*/

#include "my_base.h"
#include <stdlib.h>

char **add_to_arr(char **arr, char *added, int n_rk)
{
    char **n_arr = malloc(sizeof(char *) * (my_arrlen(arr) + 2));
    int off = 0;

    if (!n_arr)
        return (NULL);
    if (n_rk > my_arrlen(arr))
        n_rk = my_arrlen(arr);
    if (n_rk < 0)
        n_rk = 0;
    n_arr[my_arrlen(arr) + 1] = NULL;
    n_arr[n_rk] = added;
    for (int rk = 0; arr[rk]; ++rk) {
        if (rk == n_rk)
            ++off;
        n_arr[rk + off] = arr[rk];
    }
    free(arr);
    return (n_arr);
}

char **rm_in_arr(char **arr, int n_rk)
{
    char **n_arr = malloc(sizeof(char *) * my_arrlen(arr));
    int off = 0;

    free(arr[n_rk]);
    if (!n_arr)
        return (NULL);
    if (n_rk >= my_arrlen(arr))
        n_rk = my_arrlen(arr) - 1;
    if (n_rk < 0)
        n_rk = 0;
    n_arr[my_arrlen(arr) - 1] = NULL;
    for (int rk = 0; arr[rk]; ++rk) {
        if (rk == n_rk)
            ++off;
        else n_arr[rk - off] = arr[rk];
    }
    free(arr);
    return (n_arr);
}