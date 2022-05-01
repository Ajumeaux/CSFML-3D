/*
** EPITECH PROJECT, 2021
** libmy_base
** File description:
** errors
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_base.h"

int int_err_msg(char const *str)
{
    if (str)
        write(2, str, my_strlen(str));
    return (84);
}

bool bool_err_msg(char const *str)
{
    if (str)
        write(2, str, my_strlen(str));
    return (false);
}

void *null_err_msg(char const *str)
{
    if (str)
        write(2, str, my_strlen(str));
    return (NULL);
}