/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** hunter
*/
#include "my_hunter.h"


int get_power(int nb)
{
int power = 0;
    while (nb / 10 > 0) {
        power++;
        nb = nb / 10;
    }
return power;
}

int ABS(int N)
{
    return ((N<0)?(-N):(N));
}

int len_of_int(int n)
{
    int i = 0;
    n = ABS(n);
    while (n > 0) {
        i++;
        n /= 10;
    }
    return i;
}

char *score_to_str(int nb)
{
    int i = 0;
    int power = 0;
    char *str = malloc(sizeof(char) * (len_of_int(nb) + 1));
    power = get_power(nb);
    while (power >= 0) {
        str[i] = (nb / pow(10, power)) + 48;
        nb = nb % (int)pow(10, power);
        power--;
        i++;
    }
    str[i] = '\0';
    return str;
}

