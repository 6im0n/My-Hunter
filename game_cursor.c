/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/
#include "include/my_hunter.h"

void init_cursor(game_t *game)
{
    game->sprite_init[CURSOR].rect_full_source_sprite.left = 0;
    game->sprite_init[CURSOR].rect_full_source_sprite.top = 0;
    game->sprite_init[CURSOR].rect_full_source_sprite.height = 251;
    game->sprite_init[CURSOR].rect_full_source_sprite.width = 821;
    game->sprite_init[CURSOR].rect_source_sprite.left = 0;
    game->sprite_init[CURSOR].rect_source_sprite.top = 0;
    game->sprite_init[CURSOR].rect_source_sprite.height = 251;
    game->sprite_init[CURSOR].rect_source_sprite.width = 162;
    game->time = sfClock_getElapsedTime(game->clock);
    game->sprite_init[CURSOR].sprite = sfSprite_create();
    game->sprite_init[CURSOR].pos.x = 0.0;
    game->sprite_init[CURSOR].pos.y = 0.0;
    game->sprite_init[CURSOR].texture = sfTexture_createFromFile
    ("assets/cursor.png", &game->sprite_init[CURSOR].rect_full_source_sprite);
}

void set_cursor(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(window,sfFalse);
    shift_cursor(window, game);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        game->time = sfClock_getElapsedTime(game->clock);
        game->miliseconds = game->time.microseconds / 1000.0;
        move_texture_square(game);
        sfSprite_setTextureRect(game->sprite_init[CURSOR].sprite,
        game->sprite_init[CURSOR].rect_source_sprite);
        sfRenderWindow_drawSprite(window, game->sprite_init[CURSOR].sprite,
        NULL);
    } else{
        game->sprite_init[CURSOR].rect_source_sprite.left = 0;
        sfSprite_setTextureRect(game->sprite_init[CURSOR].sprite,
        game->sprite_init[CURSOR].rect_source_sprite);
        sfRenderWindow_drawSprite(window, game->sprite_init[CURSOR].sprite,
        NULL);
    }
}

void move_texture_square(game_t *game)
{
    if (game->miliseconds - game->time_ref[TIME_CURSOR] > 100) {
        if (game->sprite_init[CURSOR].rect_source_sprite.left >= 640) {
            game->sprite_init[CURSOR].rect_source_sprite.left = 0;
        } else
            game->sprite_init[CURSOR].rect_source_sprite.left += 162;
            game->time_ref[TIME_CURSOR] = game->miliseconds;
    }
}

void shift_cursor(sfRenderWindow *window, game_t *game)
{
    sfSprite_setTexture(game->sprite_init[CURSOR].sprite,
    game->sprite_init[CURSOR].texture, sfTrue);
    sfSprite_setScale(game->sprite_init[CURSOR].sprite, (sfVector2f){1.5,1.5});
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_pos_f = {mouse_pos.x - 53, mouse_pos.y - 75};
    game->sprite_init[CURSOR].pos = mouse_pos_f;
    sfSprite_setPosition(game->sprite_init[CURSOR].sprite, mouse_pos_f);

}
