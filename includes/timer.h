/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "my.h"
#include "graph.h"
#include "object.h"

#ifndef TIMER_H_
    #define TIMER_H_

    typedef struct s_Timer {
        Class base;

        int seconds;
        sfFont *font;
        sfText *text;
        sfClock *clock;
        sfTime time;
        sfFloatRect timerRect;
        sfVector2f timerPos;

    }TimerClass;

    extern const Class *Timer;

#endif
