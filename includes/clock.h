/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "my.h"
#include "graph.h"
#include "window.h"
#include "event.h"
#include "object.h"

#ifndef CLOCK_H_
    #define CLOCK_H_

    typedef struct s_ClockClass {
        Class base;

        sfClock *clock;

        sfTime (*Clock_getElapsedTime)(struct s_ClockClass*);
        sfTime (*Clock_restart)(struct s_ClockClass*);
    }ClockClass;

    extern const Class *Clock;

#endif
