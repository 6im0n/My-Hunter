/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/

#include "my_hunter.h"

void display_player_score(sfRenderWindow *window,score_t *score)
{

    char *str = score_to_str(score->score);
    char *str2 = malloc(sizeof(char)*my_strlen(str)+ 10);
    strcpy(str2,"Score : ");
    char *str3 = my_strcat(str2, str);
    sfText_setString(score->text, str3);
    sfRenderWindow_drawText(window, score->text, NULL);


}

void init_score(score_t *score)
{
    score->clock = sfClock_create();
    score->time = sfClock_getElapsedTime(score->clock);
    score->shooted = false;

    score->pos.x = 0;
    score->pos.y = 0;
    sfColor color = {255, 255, 255, 255};
    score->text = sfText_create();
    score->font = sfFont_createFromFile("assets/doom_font.ttf");
    sfText_setFont(score->text, score->font);
    sfText_setCharacterSize(score->text, 50);
    sfText_setColor(score->text, color);
    sfText_setPosition(score->text, score->pos);
}

void get_player_score(score_t *score, animated_t *animated, cursor_t *cursor)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && !score->shooted) {
        if ((animated->pos.x < cursor->pos.x + 53
        && animated->pos.x + 73 > cursor->pos.x + 53)
        && (animated->pos.y < cursor->pos.y + 45
        && animated->pos.y + 73 > cursor->pos.y + 45)) {
                score->score += 1;
                animated->pos.y = animated->pos.y + animated->random_value ;
                animated->pos.x = 0;
                score->shooted = true;
        }
    } else if (score->shooted) {
            score->time = sfClock_getElapsedTime(score->clock);
            score->miliseconds = score->time.microseconds / 1000.0;
            if (score->miliseconds > 500) {
                score->shooted = false;
                sfClock_restart(score->clock);
            }
        }
}

