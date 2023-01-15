/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** library
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

sfRenderWindow *create_my_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {width, height, 8};
    window = sfRenderWindow_create
            (video_mode, "My Window",sfClose | sfTitlebar, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}
