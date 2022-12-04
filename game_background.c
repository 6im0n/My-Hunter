/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/

#include "include/my_hunter.h"

void init_background(game_t *game)
{
    game->sprite_init[BACKGROUND_GAME].texture =
    sfTexture_createFromFile("assets/level1.jpg", NULL);
    game->sprite_init[BACKGROUND_GAME].sprite = sfSprite_create();
}

void set_background(sfRenderWindow *window, game_t *game)
{
    sfSprite_setTexture(game->sprite_init[BACKGROUND_GAME].sprite,
    game->sprite_init[BACKGROUND_GAME].texture, sfTrue);
    sfRenderWindow_drawSprite(window,
    game->sprite_init[BACKGROUND_GAME].sprite, NULL);
}
