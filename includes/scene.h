/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "my.h"
#include "graph.h"
#include "object.h"


#ifndef IMAGE_H_
    #define IMAGE_H_

    typedef struct s_SceneClass {
        Class base;

        sfRenderWindow *window;
        sfSprite *background;
        sfTexture *texture;

        void (*drawSprite) (struct s_SceneClass *, struct s_WindowClass *);
    }SceneClass;

    extern const Class *Scene;

#endif
