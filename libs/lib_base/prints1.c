/*
** EPITECH PROJECT, 2021
** libmy_base
** File description:
** prints1
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_base.h"

void my_putchar(char const c)
{
    write(1, &c, 1);
}

int show_str(char const *str)
{
    if (str == NULL)
        return (-1);
    return (write(1, str, my_strlen(str)));
}

int show_int(int nb)
{
    int neg = (nb < 0) ? -1 : 1;
    unsigned int len = int_len(nb);
    char cfrs[len + 1];

    cfrs[len] = '\0';
    nb *= neg;
    for (unsigned int i = 0; i < len; ++i, nb /= 10)
        cfrs[i] = (nb % 10) + 48;
    if (neg == -1)
        my_putchar('-');
    rev_str(cfrs);
    show_str(cfrs);
    return (len + (neg == -1 ? 1 : 0));
}