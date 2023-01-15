/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "../../../includes/my.h"
#include "../../../includes/graph.h"
#include "../../../includes/window.h"
#include "../../../includes/event.h"
#include "../../../includes/object.h"
#include "../../../includes/clock.h"

// MODEL TO FOLLOW

static sfTime clock_get_elapsed_time(ClockClass *this)
{
    return sfClock_getElapsedTime(this->clock);
}

static sfTime clock_restart(ClockClass *this)
{
    return sfClock_restart(this->clock);
}

static void clock_constructor(ClockClass *this)
{
    this->clock = sfClock_create();
}

static void clock_destructor(ClockClass *this)
{
    sfClock_destroy(this->clock);
}

static const ClockClass description = {
        {
            .size = sizeof(ClockClass),
            .constructor = (constructor)&clock_constructor,
            .destructor = (destructor)&clock_destructor,
        },
        .clock = NULL,
        .Clock_getElapsedTime = &clock_get_elapsed_time,
        .Clock_restart = &clock_restart,
};

const Class *Clock = (const Class *)&description;
