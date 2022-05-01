/*
** EPITECH PROJECT, 2021
** libmy_base
** File description:
** str_manip2
*/

#include <stdlib.h>
#include "my_base.h"

void swap_str(char **s1, char **s2)
{
    char *temp = *s1;

    *s1 = *s2;
    *s2 = temp;
}

int str_to_int(char const *str)
{
    int res = 0;
    int neg = 1;
    unsigned int rk = 0;

    if (str == NULL)
        return (0);
    while (str[rk] == '-' || str[rk] == '+') {
        neg *= (str[rk] == '-') ? -1 : 1;
        rk += 1;
    }
    for (int i = 1; str[rk] >= '0' && str[rk] <= '9'; ++rk, ++i) {
        if (i == 10)
            return (0);
        res *= 10;
        res += str[rk] - 48;
    }
    return (res * neg);
}

char *int_to_str(int const nb)
{
    unsigned int len = int_len(nb);
    char *res = malloc(sizeof(char) * (len + 1));

    if (res == NULL)
        return (NULL);
    for (unsigned int i = 0; i < len; ++i)
        res[i] = ((nb % our_pow(10, len - i)) / our_pow(10, len - i - 1)) + 48;
    res[len] = 0;
    return (res);
}

char *my_strcat2(char const *str1, char const *str2)
{
    char *res = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));

    if (!res)
        return (NULL);
    my_strcpy(res, str1);
    my_strcpy(res + my_strlen(str1), str2);
    res[my_strlen(str1) + my_strlen(str2)] = '\0';
    return (res);
}

char *my_strcat3(char const *str1, char const *str2, char const *str3)
{
    char *res = malloc(sizeof(char) * (my_strlen(str1)
    + my_strlen(str2) + my_strlen(str3) + 1));

    if (!res)
        return (NULL);
    my_strcpy(res, str1);
    my_strcpy(res + my_strlen(str1), str2);
    my_strcpy(res + my_strlen(str1) + my_strlen(str2), str3);
    res[my_strlen(str1) + my_strlen(str2) + my_strlen(str3)] = '\0';
    return (res);
}