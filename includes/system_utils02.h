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

#ifndef SYSTEM_UTILS02_H_
    #define SYSTEM_UTILS02_H_

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
    #define IN_AREA (tmp->plane->in_area)
    #define PLANE_RECT (tmp->plane->rect)
    #define PLANE_ARRIVAL (tmp->plane->arrival)
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

    #define TOP_LEFT_CORNER_DISTANCE (sqrt(pow(c_pos.x + RADIUS / 2 - \
            p_pos.x, 2) + pow(c_pos.y + RADIUS / 2 - p_pos.y, 2)))

    #define TOP_RIGHT_CORNER_DISTANCE \
            (sqrt(pow(c_pos.x + RADIUS / 2 - (p_pos.x + 20), 2) \
            + pow(c_pos.y + RADIUS / 2 - p_pos.y, 2)))

    #define BOT_LEFT_CORNER_DISTANCE (sqrt(pow(c_pos.x + RADIUS / 2 - \
            p_pos.x, 2) + pow(c_pos.y + RADIUS / 2 - (p_pos.y + 20), 2)))

    #define BOT_RIGHT_CORNER_DISTANCE (sqrt(pow(c_pos.x + RADIUS / 2 -\
            (p_pos.x + 20), 2) + pow(c_pos.y + RADIUS / 2 - (p_pos.y + 20), 2)))

    #define BEGINNING_OF_SCREEN ((sfVector2f){0, \
            sfSprite_getPosition(PLANE_SPRITE).y})

    #define ENDING_OF_SCREEN ((sfVector2f){1920, \
            sfSprite_getPosition(PLANE_SPRITE).y})

    #define TOP_OF_SCREEN ((sfVector2f) \
            {sfSprite_getPosition(PLANE_SPRITE).x, 0})

    #define BOTTOM_OF_SCREEN ((sfVector2f) \
            {sfSprite_getPosition(PLANE_SPRITE).x, 1080})

    #define GAME (this->game)
    #define OFFSET ((sfVector2f) {(float) (cos(PLANE_ANGLE * \
            (M_PI / 180)) * (double) PLANE_SPEED) / 20,(float)       \
            (sin(PLANE_ANGLE * (M_PI / 180)) * (double) PLANE_SPEED) / 20})

    #define PLACE_HOLDER_RECT (place_holder->plane->rect)
    #define PLACE_HOLDER_ID (place_holder->plane->id)
    #define PLANE_ID (tmp->plane->id)
    #define PLANE (tmp->plane)
    #define IS_PLACE_HOLDER_DESTROYED (place_holder->plane->destroyed)
    #define IS_PLACE_HOLDER_VISIBLE (place_holder->plane->visibility)
    #define IS_PLACE_HOLDER_IN_AREA (place_holder->plane->in_area)
    #define PLANE_DELAY (tmp->plane->delay)
    #define RESTART_CLOCK (this->clock->Clock_restart(this->clock))
    #define CTRL_AREA (TOWER_ARRAY[j]->ctrl_area)

    void system_state(SystemClass *this);
    plane_list_t *system_contexts_init
    (SystemClass *this, int argc, char **argv);
    void system_usage(SystemClass *this, char **argv);
    void plane_managing_loop
    (SystemClass *this, plane_list_t *tmp, unsigned long, sfVector2f p_pos);

#endif
