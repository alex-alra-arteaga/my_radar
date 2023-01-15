/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "../../../includes/my.h"
#include "../../../includes/manage_files.h"
#include "../../../includes/timer.h"

static void timer_constructor(TimerClass *this)
{
    this->seconds = 0;
    this->font = sfFont_createFromFile("assets/fonts/ComicSansMS3.ttf");
    this->text = sfText_create();
    sfText_setFont(this->text, this->font);
    sfText_setCharacterSize(this->text, 24);
    sfText_setColor(this->text, sfWhite);
    this->clock = sfClock_create();
}

static void timer_destructor(TimerClass *this)
{
    sfText_destroy(this->text);
    sfFont_destroy(this->font);
}

static const TimerClass description = {
        {
            .size = sizeof(TimerClass),
            .constructor = (constructor)&timer_constructor,
            .destructor = (destructor)&timer_destructor,
        },
};

const Class *Timer = (const Class *)&description;
