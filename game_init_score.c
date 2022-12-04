/*
** EPITECH PROJECT, 2022
** bs graphic
** File description:
** graphic
*/
#include "include/my_hunter.h"

void init_score(game_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->shooted = false;
    game->text_init[SCORE].pos.x = 0;
    game->text_init[SCORE].pos.y = 0;
    sfColor color = {255, 255, 125, 255};
    game->text_init[SCORE].text = sfText_create();
    sfFont *font;
    font = sfFont_createFromFile("assets/doom_font.ttf");
    sfText_setFont( game->text_init[SCORE].text, font);
    sfText_setCharacterSize(game->text_init[SCORE].text, 50);
    sfText_setColor(game->text_init[SCORE].text, color);
    sfText_setPosition(game->text_init[SCORE].text, game->text_init[SCORE].pos);
    sfFont_destroy(font);
}

void init_h_score(game_t *game)
{
    game->text_init[H_SCORE].pos.x = 0;
    game->text_init[H_SCORE].pos.y = 50;
    sfColor color = {255, 255, 125, 255};
    game->text_init[H_SCORE].text = sfText_create();
    sfFont *font;
    font = sfFont_createFromFile("assets/doom_font.ttf");
    sfText_setFont( game->text_init[H_SCORE].text, font);
    sfText_setCharacterSize(game->text_init[H_SCORE].text, 50);
    sfText_setColor(game->text_init[H_SCORE].text, color);
    sfText_setPosition(game->text_init[H_SCORE].text,
    game->text_init[H_SCORE].pos);
    sfFont_destroy(font);
}
