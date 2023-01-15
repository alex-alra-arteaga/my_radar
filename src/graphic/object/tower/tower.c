/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "../../../../includes/object.h"
#include "../../../../includes/my.h"
#include "../../../../includes/manage_files.h"
#include "../../../../includes/tower.h"

static tower_class *populate_tower(ParseClass *parse, tower_class *tower_arr)
{
    sfTexture *texture;
    static int id = 0;

    tower_arr->id = id++;
    tower_arr->coords.x = my_getnbr(parse->head->str_data[1]);
    tower_arr->coords.y = my_getnbr(parse->head->str_data[2]);
    tower_arr->radius = 1920 * my_getnbr(parse->head->str_data[3]) / 100;
    tower_arr->sprite = sfSprite_create();
    tower_arr->ctrl_area = sfCircleShape_create();
    texture = sfTexture_createFromFile("assets/sprites/tower.png", NULL);
    sfSprite_setTexture(tower_arr->sprite, texture, sfTrue);
    sfSprite_setPosition(tower_arr->sprite, POSITION_T);
    sfCircleShape_setPosition(tower_arr->ctrl_area, POSITION_T_C;
    sfSprite_setScale(tower_arr->sprite, (sfVector2f){0.05859, 0.05859});
    sfCircleShape_setRadius(tower_arr->ctrl_area, tower_arr->radius);
    sfCircleShape_setFillColor(tower_arr->ctrl_area, sfTransparent);
    sfCircleShape_setOutlineColor(tower_arr->ctrl_area, sfBlue);
    sfCircleShape_setOutlineThickness(tower_arr->ctrl_area, 2);
    return (tower_arr);
}

tower_class *tower_factory(ParseClass *parse)
{
    tower_class *tower_arr = new(Tower);

    tower_arr = populate_tower(parse, tower_arr);
    if (parse->head->next)
        parse->head = parse->head->next;
    return (tower_arr);
}

static void tower_constructor(tower_class *this)
{
    this->id = 0;
    this->coords.x = 0;
    this->coords.y = 0;
    this->radius = 0;
}

static void tower_destructor(tower_class *this)
{
    delete(this);
}

static const tower_class description = {
        {
            .size = sizeof(tower_class),
            .constructor = (constructor)&tower_constructor,
            .destructor = (destructor)&tower_destructor,
        },
};

const Class *Tower = (const Class *)&description;
