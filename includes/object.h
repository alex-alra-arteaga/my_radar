/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "my.h"
#include "graph.h"

#ifndef OBJECT_H_
    #define OBJECT_H_

    typedef void Object;

    typedef void (*constructor)(Object *_this, va_list *args);

    typedef void (*destructor)(Object *_this);

    typedef struct s_Class {
        const unsigned long size;
        constructor constructor;
        destructor destructor;
    }Class;

    Object *new(const Class *_class, ...);

    void delete(Object *ptr);

    void object_free(Object *obj);

#endif
