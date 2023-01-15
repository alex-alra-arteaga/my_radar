/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "../../includes/my.h"
#include "../../includes/window.h"
#include "../../includes/object.h"
#include "../../includes/system.h"
#include "../../includes/event.h"
#include "../../includes/clock.h"
#include "../../includes/manage_files.h"
#include "../../includes/system_utils.h"
#include "../../includes/system_utils02.h"

static void system_display(SystemClass *this)
{
    static unsigned long passes = 0;
    plane_list_t *tmp = GAME->plane_l;
    sfVector2f p_pos;

    for (int j = 0; NUM_TOWERS != j; j++) {
        if (!sfKeyboard_isKeyPressed(sfKeyL))
            sfRenderWindow_drawCircleShape(WINDOW, CTRL_AREA, NULL);
        if (!sfKeyboard_isKeyPressed(sfKeyS))
            sfRenderWindow_drawSprite(WINDOW, TOWER_ARRAY[j]->sprite, NULL);
    }
    plane_managing_loop(this, tmp, passes, p_pos);
    passes++;
    sfRenderWindow_display(WINDOW);
    RESTART_CLOCK;
}

static void system_contexts(SystemClass *this, int argc, char **argv)
{
    int j = 0;
    plane_class *plane;
    tower_class *tower;
    if (argc != 2)
        this->isRunning = false;
    plane_list_t *tmp = system_contexts_init(this, argc, argv);
    for (int i = 0; i < NUM_PLANES + NUM_TOWERS; i++) {
        if (FIRST_LETTER == 'A') {
            plane = plane_factory(this->parse);
            tmp->plane = plane;
            tmp->next = malloc(sizeof(plane_class));
            tmp = tmp->next;
        }
        if (FIRST_LETTER == 'T') {
            tower = tower_factory(this->parse);
            TOWER_ARRAY[j++] = tower;
        }
    }
    tmp->next = NULL;
    tmp->plane = NULL;
}

static void system_loop(SystemClass *this, int argc, char **argv)
{
    system_usage(this, argv);
    system_contexts(this, argc, argv);
    while (WINDOW_IS_OPEN && IS_RUNNING) {
        CLEAR_WINDOW;
        EVENT_POOL;
        if (ELAPSED_TIME_IN_S > 0.0005) {
            system_state(this);
            timer_display(this);
            system_display(this);
        }
    }
}

static void system_constructor(SystemClass *this, va_list *args)
{
    GAME = malloc(sizeof(Game));
    GAME->scene = new(Scene);
    GAME->window = new(Window);
    this->clock = new(Clock);
    this->game->event = new(Event);
    this->parse = new(Parse);
    TIMER_CLOCK = new(Timer);
}

static void system_destructor(SystemClass *this)
{
    GAME->window->base.destructor(GAME->window);
    this->clock->base.destructor(this->clock);
    this->game->scene->base.destructor(this->game->scene);
    this->parse->base.destructor(this->parse);
    this->timerClock->base.destructor(this->timerClock);
}

static const SystemClass description = {
        {
            .size = sizeof(SystemClass),
            .constructor = (constructor)&system_constructor,
            .destructor = (destructor)&system_destructor,
        },
        .game = NULL,
        .isRunning = true,
        .display = &system_display,
        .gameLoop = &system_loop,
};

const Class *System = (const Class *)&description;
