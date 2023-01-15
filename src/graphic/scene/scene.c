/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "../../../includes/my.h"
#include "../../../includes/graph.h"
#include "../../../includes/object.h"
#include "../../../includes/scene.h"

static void scene_draw_sprite(SceneClass *this, WindowClass *wthis)
{
    sfRenderWindow_drawSprite(wthis->window, this->background, NULL);
}

static void scene_constructor(SceneClass *this)
{
    this->background = sfSprite_create();
}

static void scene_destructor(SceneClass *this)
{
    sfSprite_destroy(this->background);
    sfTexture_destroy(this->texture);
}

static const SceneClass description = {
        {
            .size = sizeof(SceneClass),
            .constructor = (constructor)&scene_constructor,
            .destructor = (destructor)&scene_destructor,
        },
        .background = NULL,
        .texture = NULL,
        .drawSprite = &scene_draw_sprite,
};

const Class *Scene = (const Class *)&description;
