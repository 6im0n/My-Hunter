/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** my_hunter
*/
#include "include/my_hunter.h"

int game(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};
    sfEvent event;
    game_t game;
    scene_t scene;
    menu_t menu;

    window = sfRenderWindow_create(video_mode,"My_Hunter",
    sfClose | sfResize, NULL);
    init_base(window, &game, &menu);
    while (sfRenderWindow_isOpen(window)){
        while (sfRenderWindow_pollEvent(window, &event)) {
            close_event(window, event);
        }
        srand(time(0));
        load_base(window, &game, &menu, &scene);
    }
    //destroy_all(window, &game);
}

void init_base(sfRenderWindow *window, game_t *game, menu_t *menu)
{
    game->time_ref = 0;
    game->score = 0;
    game->h_score = get_score();
    sfRenderWindow_setFramerateLimit(window, 60);
    malloc_all_struct(menu, game);
    game->clock = sfClock_create();
    init_game(game);
    init_menu(menu);
}

void load_base(sfRenderWindow *window, game_t
*game, menu_t *menu, scene_t *scene)
{
    event_manager_menu(window, scene, menu);
    if (scene->game == true)
        load_game(window, game);
    else
        load_menu(window,menu);
}

void close_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}
