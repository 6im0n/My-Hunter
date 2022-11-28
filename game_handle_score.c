/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/

#include "my_hunter.h"

void display_player_score(sfRenderWindow *window,score_t *score)
{
    score->pos.x = 0;
    score->pos.y = 0;
    sfColor color = {255, 255, 255, 255};

    char *str = "Score: 0";
    score->text = sfText_create();
    score->font = sfFont_createFromFile("assets/doom_font.ttf");
    sfText_setFont(score->text, score->font);
    sfText_setString(score->text, str);
    sfText_setCharacterSize(score->text, 50);
    sfText_setColor(score->text, color);
    sfText_setPosition(score->text, score->pos);
    sfRenderWindow_drawText(window, score->text, NULL);
}

void init_score(score_t *score)
{
    score->clock = sfClock_create();
    score->time = sfClock_getElapsedTime(score->clock);
    score->shooted = false;
}

void get_player_score(score_t *score, animated_t *animated, cursor_t *cursor)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && !score->shooted) {
        if ((animated->pos.x < cursor->pos.x + 53
        && animated->pos.x + 73 > cursor->pos.x + 53)
        && (animated->pos.y < cursor->pos.y + 75
        && animated->pos.y + 73 > cursor->pos.y + 75)) {
                score->score += 1;
                fflush(0);
                printf("%d\n", score->score);
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