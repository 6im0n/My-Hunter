/*
** EPITECH PROJECT, 2022
** lib
** File description:
** lib
*/
#include "../include/my_hunter.h"

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
