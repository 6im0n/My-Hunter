/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/

#include "include/my_hunter.h"


void display_player_h_score(sfRenderWindow *window,game_t *game)
{
    char *str = score_to_str(game->h_score);
    char *str2 = malloc(sizeof(char)*my_strlen(str)+ 22);
    my_strcpy(str2,"High score : ");
    char *str3 = my_strcat(str2, str);
    sfText_setString(game->text_init[H_SCORE].text, str3);
    sfRenderWindow_drawText(window, game->text_init[H_SCORE].text, NULL);
    free(str);
}

void display_player_score(sfRenderWindow *window,game_t *game)
{

    char *str = score_to_str(game->score);
    char *str2 = malloc(sizeof(char)*my_strlen(str)+ 10);
    my_strcpy(str2,"Score : ");
    char *str3 = my_strcat(str2, str);
    sfText_setString(game->text_init[SCORE].text, str3);
    sfRenderWindow_drawText(window, game->text_init[SCORE].text, NULL);
    free(str);
}

void get_player_score(game_t *game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && !game->shooted) {
        if (shooted_monster(game)) {
                game->score += 1;
                save_hscore(game);
                game->sprite_init[ANIMATED].pos.y =
                game->sprite_init[ANIMATED].pos.y + game->ramdom_y ;
                game->sprite_init[ANIMATED].pos.x = 0;
                game->shooted = true;
        }
    } if (game->shooted) {
        game->time = sfClock_getElapsedTime(game->clock);
        game->miliseconds = game->time.microseconds / 1000.0;
        if (game->miliseconds - game->time_ref[TIME_SCORE] > 500) {
            game->shooted = false;
            game->time_ref[TIME_SCORE] = game->miliseconds;
        }
    }
}

bool shooted_monster(game_t *game)
{
    if ((game->sprite_init[ANIMATED].pos.x <
        game->sprite_init[CURSOR].pos.x + 53
        && game->sprite_init[ANIMATED].pos.x + 73 >
        game->sprite_init[CURSOR].pos.x + 53)
        && (game->sprite_init[ANIMATED].pos.y <
        game->sprite_init[CURSOR].pos.y + 45
        && game->sprite_init[ANIMATED].pos.y + 73 >
        game->sprite_init[CURSOR].pos.y + 45))
        return true;
    return false;
}
