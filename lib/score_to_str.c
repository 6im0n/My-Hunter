/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** hunter
*/
#include "../include/my_hunter.h"



char *score_to_str(int nb)
{
    int i = 0;
    int power = 0;
    char *str = malloc(sizeof(char) * (len_of_int(nb) + 1));
    power = get_power(nb);
    while (power >= 0) {
        str[i] = (nb / my_pow(10, power)) + 48;
        nb = nb % (int)my_pow(10, power);
        power--;
        i++;
    }
    str[i] = '\0';
    return str;
}
