/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/

#include "my_hunter.h"

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
    animated->sprite = sfSprite_create();
    animated->pos.x = 0.0;
    animated->pos.y = 0.0;

    animated->texture = sfTexture_createFromFile("assets/monsters.png", &animated->rect_full_source_sprite);

}

void set_animated_sprite(sfRenderWindow *window, animated_t *animated)
{

    sfSprite_setTexture(animated->sprite, animated->texture, sfTrue);
    sfSprite_setScale(animated->sprite, (sfVector2f) {1.5,1.5} );

        animated->time = sfClock_getElapsedTime(animated->clock);
        animated->miliseconds = animated->time.microseconds / 1000.0;
        if (animated->miliseconds > 75){
            if (animated->rect_source_sprite.left > 400) {
                animated->rect_source_sprite.left = 0;
                } else
                animated->rect_source_sprite.left += 73;
                shift_monster(animated); // animé avec fsclock une autre
                sfClock_restart(animated->clock);
        }
        sfSprite_setTextureRect(animated->sprite, animated->rect_source_sprite);
        sfRenderWindow_drawSprite(window, animated->sprite, NULL);

}

void shift_monster(animated_t *animated)
{
    animated->pos.x = animated->pos.x+20;
    if (animated->pos.x > 1920)
        animated->pos.x = 0.0;
    animated->pos.y = animated->pos.y + 1;
    if (animated->pos.y > 1080)
        animated->pos.y = 0.0;
    sfSprite_setPosition(animated->sprite, animated->pos);
}
