/*
** EPITECH PROJECT, 2022
** get nbr
** File description:
** get nb
*/
#include "../include/my_hunter.h"

int my_getnbr(char const *str)
{
    int true_nbr = 0;
    int result = 0;
    int pair = 0;
    int j;
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '-'){
            j++;
        }
    }
    pair = (j % 2 == 0);
    for (int i = 0; i < my_strlen(str); i++) {
        if (str [i] >= '0' && str[i] <= '9') {
            true_nbr++;
            result = result * 10 + (str[i]-'0');
        }
        if (true_nbr > 0 && (str[i] > '9' || str[i] < '0')) {
            break;
        }
    }
    return ! pair ? - result : result;
}
