/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <time.h>
#include <stdbool.h>

#ifndef STRUCTS_H_
    #define STRUCTS_H_

    typedef enum type_sprite_e{
        BACKGROUND_GAME,
        LOGO,
        ANIMATED,
        CURSOR,
        BACKGROUND_MENU,
        SPRITE_MAX
    } type_sprite_t;

    typedef enum type_text_e{
        PLAY_BTN,
        OPTION,
        CLOSE,
        SCORE,
        H_SCORE,
        TEXT_MAX
    } type_text_t;

    typedef enum time_ref_s{
        TIME_CURSOR,
        TIME_MONSTER,
        TIME_SCORE,
        TIME_MAX
    } time_ref_t;

    typedef struct text_init_s {
        sfText *text;
        sfFont *font;
        sfColor color;
        sfVector2f pos;
    } text_init_t;

    typedef struct sprite_init_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect_full_source_sprite ;
        sfIntRect rect_source_sprite;
        sfVector2f pos;
        sfVector2f scale;
    } sprite_init_t;


    typedef struct menu_s {
        sprite_init_t *sprite_init;
        text_init_t *text_init;
    } menu_t;

    typedef struct game_s {
        sprite_init_t *sprite_init;
        text_init_t *text_init;
        sfClock *clock;
        sfTime time;
        float miliseconds;
        int ramdom_y;
        bool shooted;
        int score;
        int h_score;
        float *time_ref;
    } game_t;

    typedef struct scene_s{
        bool game;
        bool option;
    } scene_t;

    typedef struct framebuffer framebuffer_t;

#endif /* !STRUCTS_H_ */
