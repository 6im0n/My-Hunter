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

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    for (int i = 0; i <= src_len + 1; i++){
        dest[(dest_len) +i ] = src[i];
    }
    return dest;
}


int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0' ) {
        i++;
    }
    return i;
}

char * my_strdup ( char const * src )
{
    char * str = malloc(sizeof(char) * my_strlen(src));
    my_strcpy(str,src);
    return str;
}

char * my_strcpy ( char * dest , char const * src )
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}