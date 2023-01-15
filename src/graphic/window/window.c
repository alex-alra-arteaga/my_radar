/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "../../../includes/my.h"
#include "../../../includes/graph.h"
#include "../../../includes/window.h"
#include "../../../includes/object.h"

static sfBool window_is_open(WindowClass *this)
{
    return sfRenderWindow_isOpen(this->window);
}

static void window_clear(WindowClass *this)
{
    sfRenderWindow_clear(this->window, sfBlack);
}

static void window_close(WindowClass *this)
{
    sfRenderWindow_close(this->window);
}

static void window_constructor(WindowClass *this)
{
    sfVideoMode video_mode = {1920, 1080, 8};
    this->window = sfRenderWindow_create
            (video_mode, "MyRadar",sfClose | sfTitlebar, NULL);
    sfRenderWindow_setFramerateLimit(this->window, 60);
}

static void window_destroy(WindowClass *this)
{
    sfRenderWindow_destroy(this->window);
}

//  instance of the Window struct
static const WindowClass description = {
        {
            .size = sizeof(WindowClass),
            .constructor = (constructor)&window_constructor,
            .destructor = (destructor)&window_destroy,
        },
        .window = NULL,
        .isOpen = &window_is_open,
        .clear = &window_clear,
        .close = &window_close,
};

const Class *Window = (const Class *)&description;
