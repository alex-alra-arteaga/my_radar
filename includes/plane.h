/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "my.h"
#include "graph.h"
#include "object.h"
#include "manage_files.h"

#ifndef PLANE_H_
    #define PLANE_H_

    #define VEC_Y ((double)plane_l->arrival.y - (double)plane_l->departure.y)
    #define VEC_X ((double)plane_l->arrival.x - (double)plane_l->departure.x)
    #define POSITION_P \
    ((sfVector2f){(float)plane_l->departure.x, (float)plane_l->departure.y})
    #define SCALE ((sfVector2f){(float)0.0701754, (float)0.07462})
    #define RECT ((sfIntRect){(int)tmp_rect.left,(int)tmp_rect.top, \
    (int)tmp_rect.width,(int)tmp_rect.width})

    typedef struct s_plane_class {
        // Class inheritance
        Class base;

        // Special attributes
        unsigned int id;
        bool visibility;
        bool destroyed;
        bool has_landed;
        bool in_area;
        double angle;
        unsigned int speed;
        unsigned int delay;
        sfVector2i departure;
        sfVector2i arrival;
        sfSprite *sprite;
        sfRectangleShape *hitbox;
        sfIntRect rect;

        struct s_plane_class *(*Plane_factory)(struct s_Parse*);
    }plane_class;

    extern const Class *Plane;
    extern plane_class *plane_factory(ParseClass *parse);

#endif
