/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "../../../includes/my.h"
#include "../../../includes/graph.h"
#include "../../../includes/window.h"
#include "object.h"
#include "../../../includes/event.h"
#include "../../../includes/window.h"

static void event_poll_event(EventClass *this, WindowClass *wthis)
{
    while (sfRenderWindow_pollEvent(wthis->window, &(this->event))) {
        if (this->event.type == sfEvtClosed)
            wthis->close(wthis);
        if (this->event.type == sfEvtKeyPressed
        && this->event.key.code == sfKeyEscape)
            wthis->close(wthis);
    }
}

static const EventClass description = {
        {
            .size = sizeof(EventClass),
        },
        .window = NULL,
        .poll = &event_poll_event,
};

const Class *Event = (const Class *)&description;
