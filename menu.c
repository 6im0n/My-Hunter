/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** hunter
*/
#include "my_hunter.h"

void init_bg_menu(menu_t *menu)
{
    menu->sprite_init[BACKGROUND].texture = sfTexture_createFromFile("assets/menu.jpg", NULL);
    menu->sprite_init[BACKGROUND].sprite = sfSprite_create();
    sfSprite_setTexture(menu->sprite_init[BACKGROUND].sprite,menu->sprite_init[BACKGROUND].texture, sfTrue);

}

void set_bg_menu(sfRenderWindow *window, menu_t *menu)
{
    sfSprite_setTexture(menu->sprite_init[BACKGROUND].sprite, menu->sprite_init[BACKGROUND].texture, sfTrue);
    sfRenderWindow_drawSprite(window, menu->sprite_init[BACKGROUND].sprite, NULL);
}

void init_play_button(menu_t *menu)
{
    sfFont *font;
    font = sfFont_createFromFile("assets/doom_font.ttf");
    menu->text_init[PLAY_BTN].text = sfText_create();
    menu->text_init[PLAY_BTN].color.a = 255;
    menu->text_init[PLAY_BTN].color.r = 255;
    menu->text_init[PLAY_BTN].color.g = 112;
    menu->text_init[PLAY_BTN].color.b = 10;
    menu->text_init[PLAY_BTN].pos.x = 1020;
    menu->text_init[PLAY_BTN].pos.y = 340;
    sfText_setFont(menu->text_init[PLAY_BTN].text, font);
    sfText_setCharacterSize(menu->text_init[PLAY_BTN].text, 100);
    sfText_setColor(menu->text_init[PLAY_BTN].text, menu->text_init[PLAY_BTN].color);
    sfText_setPosition(menu->text_init[PLAY_BTN].text, menu->text_init[PLAY_BTN].pos);
    sfText_setString(menu->text_init[PLAY_BTN].text, "Play" );
}
void init_option_button(menu_t *menu)
{
    sfFont *font;
    font = sfFont_createFromFile("assets/doom_font.ttf");
    menu->text_init[OPTION].text = sfText_create();
    menu->text_init[OPTION].color.a = 255;
    menu->text_init[OPTION].color.r = 255;
    menu->text_init[OPTION].color.g = 112;
    menu->text_init[OPTION].color.b = 10;
    menu->text_init[OPTION].pos.x = 665;
    menu->text_init[OPTION].pos.y = 420;
    sfText_setFont(menu->text_init[OPTION].text, font);
    sfText_setCharacterSize(menu->text_init[OPTION].text, 100);
    sfText_setColor(menu->text_init[OPTION].text, menu->text_init[OPTION].color);
    sfText_setPosition(menu->text_init[OPTION].text, menu->text_init[OPTION].pos);
    sfText_setString(menu->text_init[OPTION].text, "OPTION" );
}

void init_quit_button(menu_t *menu)
{
    sfFont *font;
    font = sfFont_createFromFile("assets/doom_font.ttf");
    menu->text_init[QUIT].text = sfText_create();
    menu->text_init[QUIT].color.a = 255;
    menu->text_init[QUIT].color.r = 255;
    menu->text_init[QUIT].color.g = 112;
    menu->text_init[QUIT].color.b = 10;
    menu->text_init[QUIT].pos.x = 1030;
    menu->text_init[QUIT].pos.y = 500;
    sfText_setFont(menu->text_init[QUIT].text, font);
    sfText_setCharacterSize(menu->text_init[QUIT].text, 100);
    sfText_setColor(menu->text_init[QUIT].text, menu->text_init[QUIT].color);
    sfText_setPosition(menu->text_init[QUIT].text, menu->text_init[QUIT].pos);
    sfText_setString(menu->text_init[QUIT].text, "QUIT" );
}


void set_buttons(sfRenderWindow *window, menu_t *menu)
{

    sfRenderWindow_drawText(window, menu->text_init[PLAY_BTN].text, NULL);
    sfRenderWindow_drawText(window, menu->text_init[QUIT].text, NULL);
    sfRenderWindow_drawText(window, menu->text_init[OPTION].text, NULL);
}

void init_logo(menu_t *menu)
{
    menu->sprite_init[LOGO].texture = sfTexture_createFromFile("assets/logo.png", NULL);
    menu->sprite_init[LOGO].sprite = sfSprite_create();

}

void set_logo(sfRenderWindow *window, menu_t *menu)
{
    sfSprite_setTexture(menu->sprite_init[LOGO].sprite, menu->sprite_init[LOGO].texture, sfTrue);
    sfRenderWindow_drawSprite(window, menu->sprite_init[LOGO].sprite, NULL);
    menu->sprite_init[LOGO].pos.x = 90;
    menu->sprite_init[LOGO].pos.y = 90;
    sfSprite_setScale(menu->sprite_init[LOGO].sprite, (sfVector2f){0.80, 0.80});
    sfSprite_setPosition(menu->sprite_init[LOGO].sprite, menu->sprite_init[LOGO].pos);
}

void event_manager_menu(sfRenderWindow *window,scene_t *scene, menu_t *menu)
{
    if (sfMouse_getPositionRenderWindow(window).x >= 1020
        && sfMouse_getPositionRenderWindow(window).x <= 1020 + 130
        && sfMouse_getPositionRenderWindow(window).y >= 340
        && sfMouse_getPositionRenderWindow(window).y <= 340 + 75){
            menu->text_init[PLAY_BTN].color.a = 255;
            menu->text_init[PLAY_BTN].color.r = 255;
            menu->text_init[PLAY_BTN].color.g = 0;
            menu->text_init[PLAY_BTN].color.b = 0;
            sfText_setColor(menu->text_init[PLAY_BTN].text, menu->text_init[PLAY_BTN].color);
            if (sfMouse_isButtonPressed(sfMouseLeft)){
                scene->game = true;
                sfRenderWindow_clear(window, sfBlack);

        }
    } else {
        menu->text_init[PLAY_BTN].color.a = 255;
        menu->text_init[PLAY_BTN].color.r = 255;
        menu->text_init[PLAY_BTN].color.g = 112;
        menu->text_init[PLAY_BTN].color.b = 10;
        sfText_setColor(menu->text_init[PLAY_BTN].text, menu->text_init[PLAY_BTN].color);
    }
}

