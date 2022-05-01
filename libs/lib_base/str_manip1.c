/*
** EPITECH PROJECT, 2021
** libmy_base
** File description:
** str_manip1
*/

#include <stdlib.h>
#include "my_base.h"

char *rev_str(char * const str)
{
    unsigned int len = my_strlen(str);
    char tmp;

    for (unsigned int i = 0; i < len / 2; ++i) {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
    return (str);
}

void my_strcpy(char *dest, char const *src)
{
    while (*src) {
        *dest = *src;
        ++dest;
        ++src;
    }
}

void my_strncpy(char const *src, char *dest, unsigned int const n)
{
    for (unsigned int i = 0; i < n && src[i]; ++i)
        dest[i] = src[i];
}

char *my_strdup(char const *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 1));
    char *beg = res;

    while (*str) {
        *res = *str;
        ++res;
        ++str;
    }
    *res = 0;
    return (beg);
}