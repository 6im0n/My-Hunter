/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/

#include "my_hunter.h"


void set_background(sfRenderWindow *window, background_t *background)
{

    background->texture = sfTexture_createFromFile("assets/level1.jpg", NULL);
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    sfRenderWindow_drawSprite(window, background->sprite, NULL);
}