/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/
#include "include/my_hunter.h"

int main(int argc, char const **argv)
{
    if (argc >= 2 && (my_strcmp(argv[1],"-h") == 0
    || my_strcmp(argv[1],"--help") == 0)) {
        help();
        return 0;
    } else if (argc >= 2) {
        return 84;
    }
    game();
    return 0;
}
