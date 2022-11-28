/*
** EPITECH PROJECT, 2022
** bs graphic
** File description:
** graphic
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <time.h>


#ifndef SFML_H_
    #define SFML_H_
    #define EXIT_SUCCESS 0
    #define EXIT_FAILURE 84

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

    } score_t;

    typedef struct framebuffer framebuffer_t;
    framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
    void framebuffer_destroy(framebuffer_t *framebuffer);
    void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color);



typedef struct framebuffer framebuffer_t;

#endif /* !SFML_H_ */
