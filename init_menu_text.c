/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** my hunter
*/

#include "include/my_hunter.h"

void init_option_button(menu_t *menu)
{
    menu->text_init[OPTION].font =
    sfFont_createFromFile("assets/doom_font.ttf");
    menu->text_init[OPTION].text = sfText_create();
    set_text_orange(menu, OPTION);
    menu->text_init[OPTION].pos.x = 665;
    menu->text_init[OPTION].pos.y = 420;
    sfText_setFont(menu->text_init[OPTION].text, menu->text_init[OPTION].font);
    sfText_setCharacterSize(menu->text_init[OPTION].text, 100);
    sfText_setPosition(menu->text_init[OPTION].text,
    menu->text_init[OPTION].pos);
    sfText_setString(menu->text_init[OPTION].text, "OPTION" );
}

void init_play_button(menu_t *menu)
{
    menu->text_init[PLAY_BTN].font =
    sfFont_createFromFile("assets/doom_font.ttf");
    menu->text_init[PLAY_BTN].text = sfText_create();
    set_text_orange(menu, PLAY_BTN);
    menu->text_init[PLAY_BTN].pos.x = 1020;
    menu->text_init[PLAY_BTN].pos.y = 340;
    sfText_setFont(menu->text_init[PLAY_BTN].text,
    menu->text_init[PLAY_BTN].font);
    sfText_setCharacterSize(menu->text_init[PLAY_BTN].text, 100);
    sfText_setPosition(menu->text_init[PLAY_BTN].text,
    menu->text_init[PLAY_BTN].pos);
    sfText_setString(menu->text_init[PLAY_BTN].text, "Play !" );
}

void init_hunter_logo(menu_t *menu)
{
    menu->text_init[LOGO_HUNTER].font =
    sfFont_createFromFile("assets/doom_font.ttf");
    menu->text_init[LOGO_HUNTER].text = sfText_create();
    menu->text_init[LOGO_HUNTER].pos.x = 260;
    menu->text_init[LOGO_HUNTER].pos.y = 360;
    sfText_setFont(menu->text_init[LOGO_HUNTER].text,
    menu->text_init[LOGO_HUNTER].font);
    sfText_setCharacterSize(menu->text_init[LOGO_HUNTER].text, 60);
    sfText_setPosition(menu->text_init[LOGO_HUNTER].text,
    menu->text_init[LOGO_HUNTER].pos);
    sfText_setColor(menu->text_init[LOGO_HUNTER].text, sfBlack);
    sfText_setString(menu->text_init[LOGO_HUNTER].text, "-Hunter-" );
}
