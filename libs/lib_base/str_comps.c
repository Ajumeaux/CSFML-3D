/*
** EPITECH PROJECT, 2021
** libmy_base
** File description:
** str_comps
*/

#include <stdlib.h>
#include "my_base.h"

unsigned int my_strlen(char const *str)
{
    unsigned int res = 0;

    if (str == NULL)
        return (0);
    while (*str) {
        ++res;
        ++str;
    }
    return (res);
}

int my_strcmp(char const *s1, char const *s2)
{
    if (!s1)
        return (1);
    if (!s2)
        return (-1);
    while (*s1 || *s2) {
        if (*s1 != *s2)
            return (*s1 - *s2);
        ++s1;
        ++s2;
    }
    return (0);
}

int my_strncmp(char const *s1, char const *s2, unsigned int const n)
{
    int mlen;

    if (!s1)
        return (1);
    if (!s2)
        return (-1);
    mlen = (my_strlen(s1) > my_strlen(s2)) ? my_strlen(s1) : my_strlen(s2);
    for (int i = 0; i < n && i <= mlen; ++i)
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    return (0);
}

int my_strcomp_alpha(char const *s1, char const *s2)
{
    char c1;
    char c2;

    while (*s1 && *s2) {
        c1 = T_ALPH(*s1);
        c2 = T_ALPH(*s2);
        if (c1 != c2)
            return (c1 - c2);
        ++s1;
        ++s2;
    }
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    if (my_strlen(to_find) == 0)
        return (str);
    if (my_strlen(str) < my_strlen(to_find))
        return (NULL);
    for (unsigned int i = 0; str[i] != '\0'; ++i)
        for (unsigned int j = 0; str[i + j] == to_find[j]; ++j)
            if (j + 1 == my_strlen(to_find))
                return (str + i);
    return (NULL);
}