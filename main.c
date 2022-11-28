/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "SFML.h"
#include <time.h>

int main(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};
    sfEvent event;

    animated_t animated;
    cursor_t cursor;
    score_t score;


    window = sfRenderWindow_create(video_mode,"My_Hunter", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    init_animated(&animated);
    init_cursor(&cursor);

    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        set_background(window);
        set_animated_sprite(window, &animated);
        set_cursor(window, &cursor);
        display_player_score(window,&score);
        sfRenderWindow_display(window);

    }

    /* Cleanup resources */
    sfSprite_destroy(animated.sprite);
    sfTexture_destroy(animated.texture);
    sfRenderWindow_destroy(window);

}

void init_animated(animated_t *animated)
{
    animated->rect_full_source_sprite.left = 0;
    animated->rect_full_source_sprite.top = 0;
    animated->rect_full_source_sprite.height = 556;
    animated->rect_full_source_sprite.width = 556;

    animated->rect_source_sprite.left = 0;
    animated->rect_source_sprite.top = 0;
    animated->rect_source_sprite.height = 92;
    animated->rect_source_sprite.width = 72;

    animated->clock = sfClock_create();
    animated->time = sfClock_getElapsedTime(animated->clock);
    animated->sprite = sfSprite_create();
    animated->pos.x = 0.0;
    animated->pos.y = 0.0;

    animated->texture = sfTexture_createFromFile("assets/monsters.png", &animated->rect_full_source_sprite);

}

void set_animated_sprite(sfRenderWindow *window, animated_t *animated)
{

    sfSprite_setTexture(animated->sprite, animated->texture, sfTrue);
    sfSprite_setScale(animated->sprite, (sfVector2f) {1.5,1.5} );
    shift_monster(window, animated);

        animated->time = sfClock_getElapsedTime(animated->clock);
        animated->miliseconds = animated->time.microseconds / 1000.0;
        if (animated->miliseconds > 120){
            if(animated->rect_source_sprite.left > 400) {
                animated->rect_source_sprite.left = 0;
                } else
                animated->rect_source_sprite.left += 73;
                sfClock_restart(animated->clock);
            // fflush(0);
            // printf("%d\n", animated->rect_source_sprite.left);
        }
        sfSprite_setTextureRect(animated->sprite, animated->rect_source_sprite);
        sfRenderWindow_drawSprite(window, animated->sprite, NULL);

}


void init_cursor(cursor_t *cursor)
{
    cursor->rect_full_source_sprite.left = 0;
    cursor->rect_full_source_sprite.top = 0;
    cursor->rect_full_source_sprite.height = 251;
    cursor->rect_full_source_sprite.width = 821;

    cursor->rect_source_sprite.left = 0;
    cursor->rect_source_sprite.top = 0;
    cursor->rect_source_sprite.height = 251;
    cursor->rect_source_sprite.width = 162;

    cursor->clock = sfClock_create();
    cursor->time = sfClock_getElapsedTime(cursor->clock);
    cursor->sprite = sfSprite_create();
    cursor->pos.x = 0.0;
    cursor->pos.y = 0.0;

    cursor->texture = sfTexture_createFromFile("assets/cursor.png", &cursor->rect_full_source_sprite);
}

void set_cursor(sfRenderWindow *window, cursor_t *cursor)
{
    sfEvent event;
    sfRenderWindow_setMouseCursorVisible(window,sfFalse);

    sfSprite_setTexture(cursor->sprite, cursor->texture, sfTrue);
    sfSprite_setScale(cursor->sprite, (sfVector2f) {1.5,1.5} );
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_pos_f = {mouse_pos.x-53, mouse_pos.y-75};
    sfSprite_setPosition(cursor->sprite, mouse_pos_f);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        cursor->time = sfClock_getElapsedTime(cursor->clock);
        cursor->miliseconds = cursor->time.microseconds / 1000.0;
        if (cursor->miliseconds > 75){
            if(cursor->rect_source_sprite.left >= 640) {
                cursor->rect_source_sprite.left = 0;
                } else
                cursor->rect_source_sprite.left += 162;
                sfClock_restart(cursor->clock);
            // fflush(0);
            // printf("%d\n", cursor->rect_source_sprite.left);
        }
        sfSprite_setTextureRect(cursor->sprite, cursor->rect_source_sprite);
        sfRenderWindow_drawSprite(window, cursor->sprite, NULL);
    } else{
        cursor->rect_source_sprite.left = 0;
        sfSprite_setTextureRect(cursor->sprite, cursor->rect_source_sprite);
        sfRenderWindow_drawSprite(window, cursor->sprite, NULL);
    }

}


void set_background(sfRenderWindow *window)
{
    sfTexture *texture;
    sfSprite *sprite;
    texture = sfTexture_createFromFile("assets/level1.jpg", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void shift_monster(sfRenderWindow *window, animated_t *animated)
{
    animated->pos.x = animated->pos.x+rand()%20;
    if (animated->pos.x > 1920)
        animated->pos.x = 0.0;
    animated->pos.y = animated->pos.y+rand()%20;
    if (animated->pos.y > 1080)
        animated->pos.y = 0.0;
    sfSprite_setPosition(animated->sprite, animated->pos);
}

void display_player_score(sfRenderWindow *window,score_t *score)
{
    score->pos.x = 0;
    score->pos.y = 0;
    sfColor color = {255, 255, 255, 255};
    char *str = "Score: 0";
    score->text = sfText_create();
    score->font = sfFont_createFromFile("assets/doom_font.ttf");
    sfText_setFont(score->text, score->font);
    sfText_setString(score->text, str);
    sfText_setCharacterSize(score->text, 50);
    sfText_setColor(score->text, color);
    sfText_setPosition(score->text, score->pos);
    sfRenderWindow_drawText(window, score->text, NULL);
}

void get_player_score(sfRenderWindow *window, score_t *score)
{

}