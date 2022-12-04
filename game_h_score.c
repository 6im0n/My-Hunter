/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** my_hunter
*/
#include "include/my_hunter.h"

void save_hscore(game_t *game)
{
    if (game->score > game->h_score) {
        game->h_score = game->score;
        FILE *fd;
        fd = fopen("save_score","w");
        fwrite(&game->score, sizeof(int), 1, fd);
        fclose(fd);
    }
}

int get_score(void)
{
    int score = 0;
    FILE *fd;
    fd = fopen("save_score","r");
    fread(&score,sizeof(int),1, fd);
    fclose(fd);
    return score;
}
