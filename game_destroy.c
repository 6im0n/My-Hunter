/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** my_hunter
*/
#include "include/my_hunter.h"

void destroy_all(sfRenderWindow *window, game_t *game, menu_t *menu)
{
    destroy_sprite(game, menu);
    destroy_text(game, menu);
    sfClock_restart(game->clock);
    sfClock_destroy(game->clock);
    free(game->time_ref);
    sfRenderWindow_destroy(window);
}

void destroy_text(game_t *game, menu_t *menu)
{
    for (int i = 0; i < GAME_TEXT_MAX; i++) {
        sfText_destroy(game->text_init[i].text);
        sfFont_destroy(game->text_init[i].font);
    }
    for (int i = 0; i < MENU_TEXT_MAX; i++) {
        sfText_destroy(menu->text_init[i].text);
        sfFont_destroy(menu->text_init[i].font);
    }
    free(game->text_init);
    free(menu->text_init);
}

void destroy_sprite(game_t *game, menu_t *menu)
{
    for (int i = 0; i < GAME_SPRITE_MAX; i++) {
        sfSprite_destroy(game->sprite_init[i].sprite);
        sfTexture_destroy(game->sprite_init[i].texture);
    }
    free(game->sprite_init);
    free(menu->sprite_init);
}
