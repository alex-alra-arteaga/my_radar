/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "my.h"
#include "window.h"
#include "event.h"
#include "clock.h"
#include "object.h"
#include "scene.h"
#include "manage_files.h"
#include "tower.h"
#include "timer.h"
#include "quadtree.h"

#ifndef SYSTEM_H_
    #define SYSTEM_H_

    #define RADIUS (this->game->tower_arr[c]->radius)
    #define WINDOW (this->game->window->window)
    #define TIMER_POS (this->timerClock->timerPos)
    #define TIMER_RECT (this->timerClock->timerRect)
    #define TIMER_CLOCK (this->timerClock)
    #define PLANE_HITBOX (tmp->plane->hitbox)
    #define PLANE_SPRITE (tmp->plane->sprite)
    #define PLANE_SPEED (tmp->plane->speed)
    #define PLANE_ANGLE (tmp->plane->angle)
    #define NUM_TOWERS (this->parse->cnt_towers)
    #define NUM_PLANES (this->parse->cnt_planes)
    #define TOWER_ARRAY (this->game->tower_arr)
    #define P_VISIBILITY (tmp->plane->visibility)
    #define HAS_LANDED (tmp->plane->has_landed)
    #define FIRST_LETTER (this->parse->head->str_data[0][0])
    #define IS_DESTROYED (tmp->plane->destroyed)
    #define IS_RUNNING (this->isRunning)
    #define WINDOW_IS_OPEN (this->game->window->isOpen(this->game->window))
    #define CLEAR_WINDOW (this->game->window->clear(this->game->window))
    #define EVENT_POOL (this->game->event->poll \
    (this->game->event, this->game->window))

    #define ELAPSED_TIME_IN_S (this->clock->Clock_getElapsedTime \
    (this->clock).microseconds * 10000)
    #define GAME (this->game)
    #define PLANE_DELAY (tmp->plane->delay)
    #define RESTART_CLOCK (this->clock->Clock_restart(this->clock))
    #define CTRL_AREA (TOWER_ARRAY[j]->ctrl_area)

    typedef struct plane_list {
        plane_class *plane;
        struct plane_list *next;
    }plane_list_t;

    typedef struct s_Game {
        WindowClass *window;
        EventClass *event;
        SceneClass *scene;
        plane_list_t *plane_l;
        tower_class **tower_arr;
    }Game;

    typedef struct s_SystemClass {
        Class base;

        bool isRunning;
        Game *game;
        ClockClass *clock;
        ParseClass *parse;
        TimerClass *timerClock;
        QuadtreeClass *quadtree;

        void (*gameLoop) (struct s_SystemClass *, int argc, char **argv);
        void (*display) (struct s_SystemClass *);
    }SystemClass;

    extern const Class *System;

#endif
