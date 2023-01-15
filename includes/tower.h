/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "my.h"
#include "graph.h"
#include "object.h"

#ifndef TOWER_H_
    #define TOWER_H_

    #define POSITION_T \
    ((sfVector2f){(float)tower_arr->coords.x, (float)tower_arr->coords.y})
    #define POSITION_T_C \
    ((sfVector2f){(float)tower_arr->coords.x - tower_arr->radius + 15, \
    (float)tower_arr->coords.y - tower_arr->radius + 15}))

    typedef struct s_tower_class {
        Class base;

        unsigned int id;
        sfVector2i coords;
        unsigned int radius;
        sfSprite *sprite;
        sfCircleShape *ctrl_area;

        // Methods
    }tower_class;

    extern const Class *Tower;
    extern tower_class *tower_factory(ParseClass *parse);

#endif
