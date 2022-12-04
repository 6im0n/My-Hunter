/*
** EPITECH PROJECT, 2022
** lib
** File description:
** lib
*/
#include "../include/my_hunter.h"

int get_power(int nb)
{
int power = 0;
    while (nb / 10 > 0) {
        power++;
        nb = nb / 10;
    }
return power;
}

int abs(int N)
{
    return ((N < 0) ? ( - N) : (N));
}

int len_of_int(int n)
{
    int i = 0;
    n = abs(n);
    while (n > 0) {
        i++;
        n /= 10;
    }
    return i;
}

int my_pow(int x, int a)
{
    int i = 0;
    int res = 1;
    while (i < a) {
        res *= x;
        i++;
    }
    return res;
}
