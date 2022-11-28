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

        struct framebuffer {
        unsigned int width;
        unsigned int height;
        sfUint8 *pixels;
    };

    typedef struct animated_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect_full_source_sprite ;
        sfIntRect rect_source_sprite;
        sfClock *clock;
        sfTime time;
        float miliseconds;
        sfVector2f pos

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
