/*
** EPITECH PROJECT, 2022
** Day06
** File description:
** Personal "print fonctions"
*/
#include "../include/my_hunter.h"
int compare_s1_to_s2 (char const *s1, char const *s2)
{
    int i = 0;
    while (s1[i] != 0) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    return 0;
}

int compare_s2_to_s1 (char const *s1, char const *s2)
{
    int i = 0;
    while (s2[i] != 0) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    return 0;
}

int my_strcmp (char const *s1 , char const *s2 )
{
    if (s1 == s2){
        return 0;
    }
    if (my_strlen(s1) >= my_strlen(s2)) {
        compare_s1_to_s2(s1,s2);
    } else {
        compare_s2_to_s1(s1,s2);
    }
    return 0;
}
