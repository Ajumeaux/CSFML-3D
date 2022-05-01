/*
** EPITECH PROJECT, 2021
** libmy_base
** File description:
** math1
*/

int our_pow(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    return (nb * our_pow(nb, p - 1));
}

int base_change(int nb, unsigned const char basf, unsigned const char bast)
{
    int tmp = 0;
    int neg = (nb < 0) ? -1 : 1;

    nb *= neg;
    for (int rk = 0; nb != 0; nb /= 10, ++rk)
        tmp += (nb % 10) * our_pow(basf, rk);
    for (int rk = 0; tmp != 0; tmp /= bast, ++rk) {
        nb += (tmp % bast) * our_pow(10, rk);
        if (rk > 8)
            return (0);
    }
    return (nb * neg);
}