/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "my.h"
#include "graph.h"
#include "object.h"
#include "manage_files.h"
#include "plane.h"
#include <math.h>

static plane_class *parse_plane_data(ParseClass *parse, plane_class *plane_l)
{
    static int id = 0;

    plane_l->id = id;
    plane_l->departure.x = my_getnbr(parse->head->str_data[1]);
    plane_l->departure.y = my_getnbr(parse->head->str_data[2]);
    plane_l->arrival.x = my_getnbr(parse->head->str_data[3]);
    plane_l->arrival.y = my_getnbr(parse->head->str_data[4]);
    plane_l->speed = my_getnbr(parse->head->str_data[5]);
    plane_l->delay = my_getnbr(parse->head->str_data[6]);
    plane_l->angle = atan2(VEC_Y, VEC_X) * 180 / M_PI;
    plane_l->sprite = sfSprite_create();
    plane_l->hitbox = sfRectangleShape_create();
    id++;
    return (plane_l);
}

static plane_class *populate_plane_data(plane_class *plane_l)
{
    sfTexture *texture;

    sfFloatRect tmp_rect = sfSprite_getGlobalBounds(plane_l->sprite);
    plane_l->rect = RECT;
    texture = sfTexture_createFromFile("assets/sprites/plane.png", NULL);
    sfSprite_setTexture(plane_l->sprite, texture, sfTrue);
    sfSprite_rotate(plane_l->sprite, (float)plane_l->angle);
    sfRectangleShape_rotate(plane_l->hitbox, (float)plane_l->angle);
    sfSprite_setPosition(plane_l->sprite, POSITION_P);
    sfRectangleShape_setPosition(plane_l->hitbox, POSITION_P);
    sfSprite_setScale(plane_l->sprite, SCALE);
    sfRectangleShape_setSize(plane_l->hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(plane_l->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(plane_l->hitbox, sfGreen);
    sfRectangleShape_setOutlineThickness(plane_l->hitbox, 1);
    return (plane_l);
}

plane_class *plane_factory(ParseClass *parse)
{
    plane_class *plane_l = new(Plane);

    plane_l = parse_plane_data(parse, plane_l);
    plane_l = populate_plane_data(plane_l);
    if (plane_l->departure.x == plane_l->arrival.x
    && plane_l->departure.y == plane_l->arrival.y)
        plane_l->has_landed = true;
    if (plane_l->delay == 0)
        plane_l->visibility = true;
    if (parse->head->next)
        parse->head = parse->head->next;
    return (plane_l);
}

static void plane_constructor(plane_class *this)
{
    this->id = 0;
    this->departure = (sfVector2i){0, 0};
    this->arrival.x = 0;
    this->arrival.y = 0;
    this->angle = 0;
    this->speed = 0;
    this->delay = 0;
    this->visibility = false;
    this->destroyed = false;
    this->has_landed = false;
    this->in_area = false;
}

static void plane_destructor(plane_class *this)
{
    delete(this);
}

static const plane_class description = {
        {
                .size = sizeof(plane_class),
                .constructor = (constructor)&plane_constructor,
                .destructor = (destructor)&plane_destructor,
        },
        .Plane_factory = &plane_factory,
};

const Class *Plane = (const Class *)&description;
