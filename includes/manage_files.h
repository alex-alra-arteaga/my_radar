/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "my.h"
#include "graph.h"
#include "object.h"

#ifndef MANAGE_FILES_H_
    #define MANAGE_FILES_H_

    typedef struct s_linked_list {
        char **str_data;
        struct s_linked_list *next;
    }linked_list_t;

    typedef struct s_Parse {
        Class base;

        int cnt_planes;
        int cnt_towers;
        int argc;
        char **argv;
        char **info_splitted;
        linked_list_t *head;
        bool error;

        bool (*Init_list)(struct s_Parse *, char **argv);
        void (*count_objects)(struct s_Parse *);
    } ParseClass;

    extern const Class *Parse;

#endif
