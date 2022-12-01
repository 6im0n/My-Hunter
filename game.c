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
    scene_t scene;
    menu_t menu;
    score.score = 0;
    background_t background;
    scene.game = false;

    window = sfRenderWindow_create(video_mode,"My_Hunter", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    init_game(window, &animated, &cursor, &score, &background);
    init_menu(window, &menu);

    while (sfRenderWindow_isOpen(window)){
        while (sfRenderWindow_pollEvent(window, &event)){
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        event_manager_menu(window, &scene, &menu);
        if(scene.game == true)
        load_game(window, &animated, &cursor, &score, &background);
        else
        load_menu(window,&menu);

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

void malloc_all_struct(menu_t *menu)
{
   menu->sprite_init = malloc(sizeof(sprite_init_t)* SPRITE_MAX);
   menu->text_init = malloc(sizeof(text_init_t)* TEXT_MAX);
}
void load_game(sfRenderWindow *window, animated_t *animated, cursor_t *cursor, score_t *score, background_t *background)
{
    set_background(window,background);
    set_animated_sprite(window, animated);
    set_cursor(window, cursor);
    display_player_score(window,score);
    get_player_score(score, animated, cursor);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

void init_game(sfRenderWindow *window, animated_t *animated, cursor_t *cursor, score_t *score, background_t *background)
{
    init_animated(animated);
    init_cursor(cursor);
    init_score(score);
    init_background(background);
}

void init_menu(sfRenderWindow *window, menu_t *menu)
{
    init_bg_menu(menu);
    init_play_button(menu,window);
    init_quit_button(menu,window);
    init_option_button(menu,window);
    init_logo(menu);

}

void load_menu(sfRenderWindow *window, menu_t *menu)
{
    set_bg_menu(window,menu);
    set_buttons(window, menu);
    set_logo(window, menu);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);

}
