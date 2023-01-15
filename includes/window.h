/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "my.h"
#include "graph.h"
#include "object.h"
#include "SFML/Graphics.h"

#ifndef WINDOW_H_
    #define WINDOW_H_

    typedef struct s_WindowClass {
        Class base;

        sfRenderWindow* window;

        sfBool (*isOpen)(struct s_WindowClass*); // encapsulation
        void (*clear)(struct s_WindowClass*);
        void (*close)(struct s_WindowClass*);
    } WindowClass;

    extern const Class *Window;

#endif
