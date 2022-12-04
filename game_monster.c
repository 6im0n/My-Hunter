/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/

#include "include/my_hunter.h"

void init_animated(game_t *game)
{
    game->sprite_init[ANIMATED].rect_full_source_sprite.left = 0;
    game->sprite_init[ANIMATED].rect_full_source_sprite.top = 0;
    game->sprite_init[ANIMATED].rect_full_source_sprite.height = 556;
    game->sprite_init[ANIMATED].rect_full_source_sprite.width = 556;
    game->sprite_init[ANIMATED].rect_source_sprite.left = 0;
    game->sprite_init[ANIMATED].rect_source_sprite.top = 0;
    game->sprite_init[ANIMATED].rect_source_sprite.height = 92;
    game->sprite_init[ANIMATED].rect_source_sprite.width = 72;
    game->ramdom_y = rand() % 1000;
    game->sprite_init[ANIMATED].sprite = sfSprite_create();
    game->sprite_init[ANIMATED].pos.x = 0.0;
    game->sprite_init[ANIMATED].pos.y = 0.0;
    game->sprite_init[ANIMATED].texture = sfTexture_createFromFile
    ("assets/monsters.png",
    &game->sprite_init[ANIMATED].rect_full_source_sprite);
}

void set_animated_sprite(sfRenderWindow *window, game_t *game)
{
    sfSprite_setTexture(game->sprite_init[ANIMATED].sprite,
    game->sprite_init[ANIMATED].texture, sfTrue);
    sfSprite_setScale(game->sprite_init[ANIMATED].sprite,
    (sfVector2f){1.5,1.5});
        game->time = sfClock_getElapsedTime(game->clock);
        game->miliseconds = game->time.microseconds / 1000.0;
        int score = (game->score / 5 > 1) ? game->score / 5 : 1;
        if (game->miliseconds - game->time_ref[TIME_MONSTER] > 75 / score) {
            if (game->sprite_init[ANIMATED].rect_source_sprite.left > 400) {
                game->sprite_init[ANIMATED].rect_source_sprite.left = 0;
            } else {
                game->sprite_init[ANIMATED].rect_source_sprite.left += 73;
                shift_monster(game);
                lives_manager(window,game);
                game->time_ref[TIME_MONSTER] = game->miliseconds;
            }
        }
    sfSprite_setTextureRect(game->sprite_init[ANIMATED].sprite,
    game->sprite_init[ANIMATED].rect_source_sprite);
    sfRenderWindow_drawSprite(window,game->sprite_init[ANIMATED].sprite, NULL);
}

void shift_monster(game_t *game)
{
    game->sprite_init[ANIMATED].pos.x = game->sprite_init[ANIMATED].pos.x + 20;
    game->sprite_init[ANIMATED].pos.y = game->sprite_init[ANIMATED].pos.y + 1;
    if (game->sprite_init[ANIMATED].pos.x > 1860){
        game->sprite_init[ANIMATED].pos.x = 0.0;
        game->sprite_init[ANIMATED].pos.y =
        game->sprite_init[ANIMATED].pos.y + game->ramdom_y;
        game->lives--;
    }
    if (game->sprite_init[ANIMATED].pos.y > 1000)
        game->sprite_init[ANIMATED].pos.y = 0.0;
    sfSprite_setPosition(game->sprite_init[ANIMATED].sprite,
    game->sprite_init[ANIMATED].pos);
}

void lives_manager(sfRenderWindow *window, game_t *game)
{
    if (game->lives == 0)
        sfRenderWindow_close(window);
}
