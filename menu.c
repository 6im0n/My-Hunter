/*
** EPITECH PROJECT, 2022
** my hunter
** File description:
** hunter
*/
#include "include/my_hunter.h"

void event_manager_menu(sfRenderWindow *window, scene_t *scene, menu_t *menu)
{
    if (hit_box_manager_menu(window,menu,PLAY_BTN))
        click_event_load_game(window,scene);
    else
        set_text_orange(menu,PLAY_BTN);
    if (hit_box_manager_menu(window,menu,OPTION))
        click_event_close(window,scene);
    else
        set_text_orange(menu,OPTION);
    if (hit_box_manager_menu(window,menu,CLOSE))
        click_event_close(window,scene);
    else
        set_text_orange(menu,CLOSE);
}

void click_event_close(sfRenderWindow *window, scene_t *scene)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && !scene->game)
    sfRenderWindow_close(window);
}

void click_event_load_game(sfRenderWindow *window, scene_t *scene)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && !scene->game) {
        scene->game = true;
        sfRenderWindow_clear(window, sfBlack);
    }
}

bool hit_box_manager_menu(sfRenderWindow *window, menu_t *menu, int sprite_enum)
{
    if (sfMouse_getPositionRenderWindow(window).x >=
    menu->text_init[sprite_enum].pos.x
    && sfMouse_getPositionRenderWindow(window).x <=
    menu->text_init[sprite_enum].pos.x + 150
    && sfMouse_getPositionRenderWindow(window).y >=
    menu->text_init[sprite_enum].pos.y
    && sfMouse_getPositionRenderWindow(window).y <=
    menu->text_init[sprite_enum].pos.y + 75) {
        sfText_setColor(menu->text_init[sprite_enum].text, sfRed);
        return true;
    }
    return false;
}
