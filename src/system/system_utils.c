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
#include <math.h>

void timer_display(SystemClass *this)
{
    char *timer;
    TIMER_CLOCK->time = sfClock_getElapsedTime(TIMER_CLOCK->clock);
    TIMER_CLOCK->seconds = (TIMER_CLOCK->time.microseconds / 1000000);
    timer = my_int_to_str(TIMER_CLOCK->seconds);
    sfText_setString(TIMER_CLOCK->text, timer);
    TIMER_RECT = sfText_getLocalBounds(TIMER_CLOCK->text);
    TIMER_POS = (sfVector2f){1920 - TIMER_RECT.width - 10, 10};
    sfText_setPosition(TIMER_CLOCK->text, TIMER_POS);
    sfRenderWindow_drawText(WINDOW, TIMER_CLOCK->text, NULL);
}

void plane_interactions
(SystemClass *this, plane_list_t *tmp, sfVector2f p_pos)
{
    sfVector2f c_pos;
    sfRectangleShape_move(PLANE_HITBOX,OFFSET);
    sfSprite_move(PLANE_SPRITE,OFFSET);
    if (!sfKeyboard_isKeyPressed(sfKeyL))
        sfRenderWindow_drawRectangleShape(WINDOW, PLANE_HITBOX, NULL);
    if (!sfKeyboard_isKeyPressed(sfKeyS))
        sfRenderWindow_drawSprite(WINDOW, PLANE_SPRITE, NULL);
    for (int c = 0; c < NUM_TOWERS; c++) {
        c_pos = sfCircleShape_getPosition(TOWER_ARRAY[c]->ctrl_area);
        if (TOP_LEFT_CORNER_DISTANCE <= RADIUS ||
            TOP_RIGHT_CORNER_DISTANCE <= RADIUS ||
            BOT_LEFT_CORNER_DISTANCE <= RADIUS ||
            BOT_RIGHT_CORNER_DISTANCE <= RADIUS) {
            IN_AREA = true;
            break;
        } else
            IN_AREA = false;
    }
}

void manage_plane_intersections(SystemClass *this, plane_list_t *tmp)
{
    int i = 0;
    plane_list_t *place_holder = tmp;

    while (i++ < NUM_PLANES && PLANE != NULL) {
        if (P_VISIBILITY && PLANE_ID != PLACE_HOLDER_ID
            && sfIntRect_intersects(&PLACE_HOLDER_RECT, &PLANE_RECT, NULL)
            && (!IN_AREA || !IS_PLACE_HOLDER_IN_AREA)) {
            IS_PLACE_HOLDER_DESTROYED = true;
            IS_PLACE_HOLDER_VISIBLE = false;
            IS_DESTROYED = true;
            P_VISIBILITY = false;
        }
        if (tmp->next == NULL)
            tmp = GAME->plane_l;
        else
            tmp = tmp->next;
    }
    tmp = place_holder;
}

void plane_manage_visibility
(SystemClass *this, plane_list_t *tmp, sfVector2f p_pos)
{
    PLANE_RECT = (sfIntRect){(int)p_pos.x - 10, (int)p_pos.y - 10, 20, 20};
    if (sfIntRect_contains(&PLANE_RECT, PLANE_ARRIVAL.x, PLANE_ARRIVAL.y)) {
        P_VISIBILITY = false;
        HAS_LANDED = true;
    }
    manage_plane_intersections(this, tmp);
}

void plane_manage_screen_appearance(plane_list_t *tmp, sfVector2f p_pos)
{
    if (p_pos.x > 1920) {
        sfSprite_setPosition(PLANE_SPRITE, BEGINNING_OF_SCREEN);
        sfRectangleShape_setPosition(PLANE_HITBOX, BEGINNING_OF_SCREEN);
    }
    if (p_pos.x < 0) {
        sfSprite_setPosition(PLANE_SPRITE, ENDING_OF_SCREEN);
        sfRectangleShape_setPosition(PLANE_HITBOX, ENDING_OF_SCREEN);
    }
    if (p_pos.y > 1080) {
        sfSprite_setPosition(PLANE_SPRITE, TOP_OF_SCREEN);
        sfRectangleShape_setPosition(PLANE_HITBOX, TOP_OF_SCREEN);
    }
    if (p_pos.y < 0) {
        sfSprite_setPosition(PLANE_SPRITE, BOTTOM_OF_SCREEN);
        sfRectangleShape_setPosition(PLANE_HITBOX, BOTTOM_OF_SCREEN);
    }
}
