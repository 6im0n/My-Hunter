/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/

#include "include/my_hunter.h"

void set_bg_menu(sfRenderWindow *window, menu_t *menu)
{
    sfSprite_setTexture(menu->sprite_init[BACKGROUND_MENU].sprite,
    menu->sprite_init[BACKGROUND_MENU].texture, sfTrue);
    sfRenderWindow_drawSprite(window,
    menu->sprite_init[BACKGROUND_MENU].sprite, NULL);
}

void set_buttons(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_drawText(window, menu->text_init[PLAY_BTN].text, NULL);
    sfRenderWindow_drawText(window, menu->text_init[CLOSE].text, NULL);
    sfRenderWindow_drawText(window, menu->text_init[OPTION].text, NULL);
}

void set_logo(sfRenderWindow *window, menu_t *menu)
{
    sfSprite_setTexture(menu->sprite_init[LOGO].sprite,
    menu->sprite_init[LOGO].texture, sfTrue);
    sfRenderWindow_drawSprite(window, menu->sprite_init[LOGO].sprite, NULL);
    menu->sprite_init[LOGO].pos.x = 90;
    menu->sprite_init[LOGO].pos.y = 90;
    sfSprite_setScale(menu->sprite_init[LOGO].sprite, (sfVector2f){0.80, 0.80});
    sfSprite_setPosition(menu->sprite_init[LOGO].sprite,
    menu->sprite_init[LOGO].pos);
}

void set_text_orange(menu_t *menu, int sprite_enum)
{
    menu->text_init[sprite_enum].color.a = 255;
    menu->text_init[sprite_enum].color.r = 255;
    menu->text_init[sprite_enum].color.g = 112;
    menu->text_init[sprite_enum].color.b = 10;
    sfText_setColor(menu->text_init[sprite_enum].text,
    menu->text_init[sprite_enum].color);
}
