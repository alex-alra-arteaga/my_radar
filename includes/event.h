/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "my.h"
#include "graph.h"
#include "object.h"
#include "window.h"

#ifndef EVENT_H_
    #define EVENT_H_

    typedef struct s_EventClass {
        Class base;

        sfEvent event;
        WindowClass *window;

        void (*poll)(struct s_EventClass *, struct s_WindowClass *);
    }EventClass;

    extern const Class *Event;

#endif
