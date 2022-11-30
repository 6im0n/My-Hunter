/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** my_hunter
*/
#include "my_hunter.h"

int game(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};
    sfEvent event;
    animated_t animated;
    cursor_t cursor;
    score_t score;
    score.score = 0;
    background_t background;
    window = sfRenderWindow_create(video_mode,"My_Hunter", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    init_animated(&animated);
    init_cursor(&cursor);
    init_score(&score);
    init_background(&background);

    while (sfRenderWindow_isOpen(window)){
        while (sfRenderWindow_pollEvent(window, &event)){
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        load_all(window, &animated, &cursor, &score, &background);
        get_player_score(&score, &animated, &cursor);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    destroy_all(window, &animated, &cursor, &score, &background);

}

void destroy_all(sfRenderWindow *window, animated_t *animated, cursor_t *cursor, score_t *score, background_t *background)
{
    sfSprite_destroy(animated->sprite);
    sfTexture_destroy(animated->texture);
    sfText_destroy(score->text);
    sfFont_destroy(score->font);
    sfSprite_destroy(cursor->sprite);
    sfTexture_destroy(cursor->texture);
    sfSprite_destroy(background->sprite);
    sfTexture_destroy(background->texture);
    sfRenderWindow_destroy(window);
}

void load_all(sfRenderWindow *window, animated_t *animated, cursor_t *cursor, score_t *score, background_t *background)
{
    set_background(window,background);
    set_animated_sprite(window, animated);
    set_cursor(window, cursor);
    display_player_score(window,score);
}
