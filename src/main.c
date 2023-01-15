/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "../includes/my.h"
#include "../includes/scene.h"
#include "../includes/window.h"
#include "../includes/object.h"
#include "../includes/system.h"

int main(int ac, char **av)
{
    SystemClass *system = new(System);

    system->gameLoop(system, ac, av);

    delete(system);
    return (0);
}
