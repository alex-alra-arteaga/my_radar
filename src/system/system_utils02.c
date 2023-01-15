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

void system_state(SystemClass *this)
{
    plane_list_t *tmp = GAME->plane_l;

    while (tmp->next) {
        if (IS_DESTROYED || HAS_LANDED)
            tmp = tmp->next;
        else
            return;
    }
    IS_RUNNING = false;
}

plane_list_t *system_contexts_init
(SystemClass *this, int argc, char **argv)
{
    plane_list_t *tmp;
    bool error;

    GAME->plane_l = malloc(sizeof(plane_list_t));
    GAME->plane_l->plane = NULL;
    GAME->plane_l->next = NULL;
    this->isRunning = this->parse->Init_list(this->parse, argv);
    this->parse->count_objects(this->parse);
    TOWER_ARRAY = malloc(sizeof(tower_class) * NUM_TOWERS);
    tmp = GAME->plane_l;
    return (tmp);
}

void system_usage(SystemClass *this, char **argv)
{
    if (argv[1] && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("Air traffic simulation panel\n\n");
        my_putstr("USAGE\n");
        my_putstr(" ./my_radar [OPTIONS] path_to_script\n");
        my_putstr("  path_to_script    The path to the script file.\n\n");
        my_putstr("OPTIONS\n");
        my_putstr(" -h\t\t\tprint the usage and quit.\n\n");
        my_putstr("USER INTERACTIONS\n");
        my_putstr(" 'L' key\tenable/disable hitboxes and areas.\n");
        my_putstr(" 'S' key\tenable/disable sprites\n");
        this->isRunning = false;
    }
}

void plane_managing_loop
(SystemClass *this, plane_list_t *tmp, unsigned long passes, sfVector2f p_pos)
{
    while (tmp->next) {
        if (0.017 * passes > PLANE_DELAY && !HAS_LANDED && !IS_DESTROYED)
            P_VISIBILITY = true;
        p_pos = sfSprite_getPosition(PLANE_SPRITE);
        plane_manage_screen_appearance(tmp, p_pos);
        if (P_VISIBILITY) {
            plane_interactions(this, tmp, p_pos);
            plane_manage_visibility(this, tmp, p_pos);
        }
        tmp = tmp->next;
    }
}
