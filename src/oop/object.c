/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "string.h"
#include "../../includes/my.h"
#include "../../includes/graph.h"
#include "../../includes/object.h"

Object *new(const Class *_class, ...)
{
    va_list ap;
    Class *objectClass;

    va_start(ap, _class);
    objectClass = malloc(_class->size);
    my_memcpy(objectClass, _class, _class->size);
    if (objectClass->constructor != NULL) {
        objectClass->constructor(objectClass, &ap);
    }
    va_end(ap);
    return (objectClass);
}

void delete(Object *ptr)
{
    Class *object = (Class *)ptr;
    if (object != NULL && object->destructor != NULL)
        object->destructor(object);
    free(object);
}

void object_free(Object *obj)
{
    free(obj);
}
