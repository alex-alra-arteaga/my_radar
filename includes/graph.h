/*
** EPITECH PROJECT, 2022
** graph.h
** File description:
** Contains the prototypes of all the functions in libmy.a
*/


#ifndef GRAPH_H_
    #define GRAPH_H_

    #include <stdbool.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Keyboard.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/VideoMode.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/Window/Window.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include "my.h"
    #include "window.h"
    #include "plane.h"
    #include "scene.h"
    #include "object.h"
    #include "system.h"
    #include "clock.h"
    #include "event.h"

    sfRenderWindow *create_my_window(unsigned int width, unsigned int height);

#endif
