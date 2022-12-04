/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** hunter like
*/

#include "include/my_hunter.h"

void help(void)
{
    write(1, "\n-------------------------\n"
    "  DOOM'S HUNTER HELPER"
    "\n-------------------------\n"
    "USAGE :\n"
    "\t./my_hunter\n"
    "\n"
    "DESCRIPTION :\n"
    "\tThe goal of the game is to kill a monster as many as possible.\n"
    "\n"
    "HOW TO PLAY :\n"
    "\tYou have to left-click on the monster that kill the monster\n"
    "\tIf you miss 3 shots the game it's over\n"
    "\tEvery time you hit the bird, the speed of the monster increases\n"
    , 358);
}
