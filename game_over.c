/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/

#include "include/my_hunter.h"

void init_game_over(game_t *game)
{
    game->text_init[G_OVER].pos.x = 900;
    game->text_init[G_OVER].pos.y = 400;
    sfColor color = {255, 255, 125, 255};
    game->text_init[G_OVER].text = sfText_create();
    game->text_init[G_OVER].font =
    sfFont_createFromFile("assets/doom_font.ttf");
    sfText_setFont(game->text_init[G_OVER].text,
    game->text_init[G_OVER].font);
    sfText_setCharacterSize(game->text_init[G_OVER].text, 100);
    sfText_setColor(game->text_init[G_OVER].text, color);
    sfText_setPosition(game->text_init[G_OVER].text,
    game->text_init[G_OVER].pos);
}

void display_game_over(sfRenderWindow *window,game_t *game)
{
    init_game_over(game);
    sfText_setString(game->text_init[G_OVER].text, "GAME\nOVER !");
    sfRenderWindow_drawText(window, game->text_init[G_OVER].text, NULL);
    sfRenderWindow_display(window);
}

void lives_manager(sfRenderWindow *window, scene_t *scene, game_t *game)
{
    if (game->lives == 0){
        display_game_over(window,game);
        sfRenderWindow_setMouseCursorVisible(window,sfTrue);
        sfSleep(sfMilliseconds(2000));
        scene->game = false;
        sfRenderWindow_clear(window, sfBlack);
    }
}
