/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/

#include "include/my_hunter.h"

void init_bg_menu(menu_t *menu)
{
    menu->sprite_init[BACKGROUND_MENU].texture =
    sfTexture_createFromFile("assets/menu.jpg", NULL);
    menu->sprite_init[BACKGROUND_MENU].sprite = sfSprite_create();
    sfSprite_setTexture(menu->sprite_init[BACKGROUND_MENU].sprite,
    menu->sprite_init[BACKGROUND_MENU].texture, sfTrue);

}

void init_option_button(menu_t *menu)
{
    sfFont *font;
    font = sfFont_createFromFile("assets/doom_font.ttf");
    menu->text_init[OPTION].text = sfText_create();
    set_text_orange(menu, OPTION);
    menu->text_init[OPTION].pos.x = 665;
    menu->text_init[OPTION].pos.y = 420;
    sfText_setFont(menu->text_init[OPTION].text, font);
    sfText_setCharacterSize(menu->text_init[OPTION].text, 100);
    sfText_setPosition(menu->text_init[OPTION].text,
    menu->text_init[OPTION].pos);
    sfText_setString(menu->text_init[OPTION].text, "OPTION" );
}

void init_play_button(menu_t *menu)
{
    sfFont *font;
    font = sfFont_createFromFile("assets/doom_font.ttf");
    menu->text_init[PLAY_BTN].text = sfText_create();
    set_text_orange(menu, PLAY_BTN);
    menu->text_init[PLAY_BTN].pos.x = 1020;
    menu->text_init[PLAY_BTN].pos.y = 340;
    sfText_setFont(menu->text_init[PLAY_BTN].text, font);
    sfText_setCharacterSize(menu->text_init[PLAY_BTN].text, 100);
    sfText_setPosition(menu->text_init[PLAY_BTN].text,
    menu->text_init[PLAY_BTN].pos);
    sfText_setString(menu->text_init[PLAY_BTN].text, "Play !" );
}

void init_logo(menu_t *menu)
{
    menu->sprite_init[LOGO].texture = sfTexture_createFromFile
    ("assets/logo.png", NULL);
    menu->sprite_init[LOGO].sprite = sfSprite_create();

}

void init_quit_button(menu_t *menu)
{
    sfFont *font;
    font = sfFont_createFromFile("assets/doom_font.ttf");
    menu->text_init[CLOSE].text = sfText_create();
    set_text_orange(menu, CLOSE);
    menu->text_init[CLOSE].pos.x = 1030;
    menu->text_init[CLOSE].pos.y = 500;
    sfText_setFont(menu->text_init[CLOSE].text, font);
    sfText_setCharacterSize(menu->text_init[CLOSE].text, 100);
    sfText_setPosition(menu->text_init[CLOSE].text,
    menu->text_init[CLOSE].pos);
    sfText_setString(menu->text_init[CLOSE].text, "CLOSE" );
}
