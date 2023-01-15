/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

/*
#include "../../../../includes/my.h"
#include "../../../../includes/object.h"
#include "../../../../includes/manage_files.h"
#include "../../../../includes/plane.h"
#include "../../../../includes/quadtree.h"

// check collisions in each quadrant
static void Query_quadrant(QuadtreeClass *this, SystemClass *sthis)
{
    for (int i = 0; i < 4; i++) {
        // Check for collisions within the linked list of planes
        this->temp = this->quadrant[i].planes;
        while (this->temp != NULL) {
            // Check for collisions with other planes in the same quadrant
            plane_list *collisionPlane = this->temp->next;
            while (collisionPlane != NULL) {
                if (sfIntRect_intersects
                (&this->temp->plane->rect, &collisionPlane->plane->rect, NULL)
                && currentPlane->plane->in_area == false) {
                    this->temp->plane->visibility = false;
                    collisionPlane->plane->visibility = false;
                }
                collisionPlane = collisionPlane->next;
            }
            this->temp = this->temp->next;
        }
    }
}

// put planes into each quadrant
static void Manage_planes_l
(QuadtreeClass *this, SystemClass *sthis, ParseClass *pthis)
{
    for (int i = 0; i < 4; i++)
        this->quadrant[i].planes = NULL;
    plane_list_t *tmp = sthis->game->plane_l;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < pthis->cnt_planes && tmp->next; j++) {
            if (sfIntRect_intersects
            (&this->quadrant->bounds, &sthis->game->plane_l->plane->rect,
            NULL)) {
                this->quadrant[i].planes->plane = tmp->plane;
                this->quadrant[i].planes = this->quadrant[i].planes->next;
            }
            tmp = tmp->next;
        }
    }
}

static void Quadtree_constructor(QuadtreeClass *this)
{
    this->quadrant[4];
    sfIntRect screenBounds = {0, 0, 1920, 1080};
    this->quadrant[0].bounds = (sfIntRect){0, 0, 1920 / 2, 1080 / 2};
    this->quadrant[1].bounds = (sfIntRect){1920 / 2, 0, 1920 / 2, 1080 / 2};
    this->quadrant[2].bounds = (sfIntRect){0, 1080 / 2, 1920 / 2, 1080 / 2};
    this->quadrant[3].bounds =
    (sfIntRect){1920 / 2, 1080 / 2, 1920 / 2, 1080 / 2};
}

//static void Quadtree_destructor(QuadtreeClass *this)
//{
//    _delete(this);
//}

static const QuadtreeClass description = {
        {
            .size = sizeof(QuadtreeClass),
            //.constructor = (constructor)&Quadtree_constructor,
            //.destructor = (destructor)&Quadtree_destructor,
        },
        //.plane_into_quadtree = &Quadtree_insert_plane,
};

const Class *Quadtree = (const Class *)&description;
 */
