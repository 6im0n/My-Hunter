/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** my_hunter
*/
#include "include/my_hunter.h"



void malloc_all_struct(menu_t *menu, game_t *game)
{
    game->text_init = malloc(sizeof(text_init_t)* GAME_TEXT_MAX);
    game->sprite_init = malloc(sizeof(sprite_init_t)* GAME_SPRITE_MAX);
    menu->sprite_init = malloc(sizeof(sprite_init_t)* MENU_SPRITE_MAX);
    menu->text_init = malloc(sizeof(text_init_t)* MENU_TEXT_MAX);
    game->time_ref = malloc(sizeof(float)*TIME_MAX);
}

void load_game(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window,sfBlack);
    set_background(window,game);
    set_animated_sprite(window, game);
    set_cursor(window, game);
    display_player_score(window,game);
    get_player_score(game);
    display_player_h_score(window,game);
    display_player_lives(window,game);
    sfRenderWindow_display(window);
}

void init_game(game_t *game)
{
    init_animated(game);
    init_cursor(game);
    init_score(game);
    init_background(game);
    init_h_score(game);
    init_lives(game);
}

void init_menu(menu_t *menu)
{
    init_bg_menu(menu);
    init_play_button(menu);
    init_quit_button(menu);
    init_option_button(menu);
    init_hunter_logo(menu);
    init_logo(menu);

}

void load_menu(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_clear(window, sfBlack);
    set_bg_menu(window,menu);
    set_buttons(window, menu);
    set_logo(window, menu);
    sfRenderWindow_display(window);

}
