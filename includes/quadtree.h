/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "object.h"

#ifndef QUADTREE_H_
    #define QUADTREE_H_

    typedef struct linked_list {
        plane_class *plane;
        struct linked_list *next;
    }plane_list;

    typedef struct s_Quadrant {
        sfIntRect bounds;
        plane_list *planes;
        tower_class *tower;
    }Quadrant;

    typedef struct s_Quadtree {
        Class base;

        Quadrant *quadrant;
        plane_list *temp;
    }QuadtreeClass;

    extern const Class *Quadtree;

#endif
