/*
** EPITECH PROJECT, 2022
** bs graphic
** File description:
** graphic
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "my_hunter_structs.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


#ifndef SFML_H_
    #define SFML_H_
    #define EXIT_SUCCESS 0
    int game(void);
    char *score_to_str(int nb);
    void init_animated(game_t *game);
    char * my_strcpy ( char * dest , char const * src );
    void set_animated_sprite(sfRenderWindow *window, game_t *game);
    void init_cursor(game_t *game);
    void set_cursor(sfRenderWindow *window, game_t *game);
    void set_background(sfRenderWindow *window, game_t *game);
    void shift_monster(game_t *game);
    void display_player_score(sfRenderWindow *window,game_t *game);
    void init_score(game_t *game);
    void get_player_score(game_t *game);
    void shift_cursor(sfRenderWindow *window, game_t *game);
    void destroy_all(sfRenderWindow *window, game_t *game);
    void load_all(sfRenderWindow *window, game_t *game);
    bool hit_box_manager_menu(sfRenderWindow *window, menu_t *menu,
    int sprite_enum);
    void event_manager_menu(sfRenderWindow *window, scene_t *scene,
    menu_t *menu);
    void init_menu(menu_t *menu);
    void load_menu(sfRenderWindow *window, menu_t *menu);
    void init_game(game_t *game);
    void load_game(sfRenderWindow *window, game_t *game);
    void malloc_all_struct(menu_t *menu, game_t *game);
    void init_background(game_t *game);
    void init_cursor(game_t *game);
    void init_animated(game_t *game);
    void init_score(game_t *game);
    void init_bg_menu(menu_t *menu);
    void init_play_button(menu_t *menu);
    void init_quit_button(menu_t *menu);
    void init_option_button(menu_t *menu);
    void init_logo(menu_t *menu);
    void set_bg_menu(sfRenderWindow *window, menu_t *menu);
    void set_play_button(sfRenderWindow *window, menu_t *menu);
    void set_quit_button(sfRenderWindow *window, menu_t *menu);
    void set_option_button(sfRenderWindow *window, menu_t *menu);
    void set_logo(sfRenderWindow *window, menu_t *menu);
    void set_background(sfRenderWindow *window, game_t *game);
    void set_animated_sprite(sfRenderWindow *window, game_t *game);
    void set_cursor(sfRenderWindow *window, game_t *game);
    void display_player_score(sfRenderWindow *window,game_t *game);
    void get_player_score(game_t *game);
    void shift_cursor(sfRenderWindow *window, game_t *game);
    void shift_monster(game_t *game);
    void destroy_all(sfRenderWindow *window, game_t *game);
    void orange_color(menu_t *menu, int sprite_enum);
    void set_buttons(sfRenderWindow *window, menu_t *menu);
    bool shooted_monster(game_t *game);

#endif /* !SFML_H_ */
