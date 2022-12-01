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
        BACKGROUND,
        LOGO,
        SPRITE_MAX
    } type_sprite_t;

    typedef enum type_text_e{
        PLAY_BTN,
        OPTION,
        QUIT,
        TEXT_MAX
    } type_text_t;

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


    typedef struct scene_s{
        bool game;
        bool option;
    } scene_t;

    typedef struct animated_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect_full_source_sprite ;
        sfIntRect rect_source_sprite;
        sfClock *clock;
        sfTime time;
        float miliseconds;
        sfVector2f pos;
        int random_value;

    } animated_t;

    typedef struct cursor_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect_full_source_sprite ;
        sfIntRect rect_source_sprite;
        sfClock *clock;
        sfTime time;
        float miliseconds;
        sfVector2f pos
    } cursor_t;

    typedef struct score_s {
        sfText *text;
        sfFont *font;
        sfVector2f pos;
        int score;
        sfClock *clock;
        sfTime time;
        float miliseconds;
        bool shooted;

    } score_t;

    typedef struct background_s {
        sfTexture *texture;
        sfSprite *sprite;
    } background_t;

    typedef struct framebuffer framebuffer_t;

#endif /* !STRUCTS_H_ */
