/*
** EPITECH PROJECT, 2022
** bs graphic
** File description:
** graphic
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "my_hunter_structs.h"


#ifndef SFML_H_
    #define SFML_H_
    #define EXIT_SUCCESS 0
    #define EXIT_FAILURE 84
    int game(void);
    char *score_to_str(int nb);
    void init_animated(animated_t *animated);
    char * my_strcpy ( char * dest , char const * src );
    void set_animated_sprite(sfRenderWindow *window, animated_t *animated);
    void init_cursor(cursor_t *cursor);
    void set_cursor(sfRenderWindow *window, cursor_t *cursor);
    void set_background(sfRenderWindow *window, background_t *background);
    void shift_monster(animated_t *animated);
    void display_player_score(sfRenderWindow *window,score_t *score);
    void init_score(score_t *score);
    void get_player_score(score_t *score, animated_t *animated, cursor_t *cursor);
    void shift_cursor(sfRenderWindow *window, cursor_t *cursor);
    void destroy_all(sfRenderWindow *window, animated_t *animated, cursor_t *cursor, score_t *score, background_t *background);
    void load_all(sfRenderWindow *window, animated_t *animated, cursor_t *cursor, score_t *score, background_t *background);


#endif /* !SFML_H_ */
