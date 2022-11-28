/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/

#include "my_hunter.h"

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
    sfRenderWindow_setMouseCursorVisible(window,sfFalse);
    shift_cursor(window, cursor);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        cursor->time = sfClock_getElapsedTime(cursor->clock);
        cursor->miliseconds = cursor->time.microseconds / 1000.0;
        if (cursor->miliseconds > 75){
            if (cursor->rect_source_sprite.left >= 640) {
                cursor->rect_source_sprite.left = 0;
                } else
                cursor->rect_source_sprite.left += 162;
                sfClock_restart(cursor->clock);
        }
        sfSprite_setTextureRect(cursor->sprite, cursor->rect_source_sprite);
        sfRenderWindow_drawSprite(window, cursor->sprite, NULL);
    } else{
        cursor->rect_source_sprite.left = 0;
        sfSprite_setTextureRect(cursor->sprite, cursor->rect_source_sprite);
        sfRenderWindow_drawSprite(window, cursor->sprite, NULL);
    }

}

void shift_cursor(sfRenderWindow *window, cursor_t *cursor)
{
    sfSprite_setTexture(cursor->sprite, cursor->texture, sfTrue);
    sfSprite_setScale(cursor->sprite, (sfVector2f) {1.5,1.5} );
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_pos_f = {mouse_pos.x - 53, mouse_pos.y - 75};
    cursor->pos = mouse_pos_f;
    sfSprite_setPosition(cursor->sprite, mouse_pos_f);

}
