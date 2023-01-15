/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "../../../includes/my.h"
#include "../../../includes/manage_files.h"
#include "../../../includes/manage_files_utils.h"

static void count_objects(ParseClass *this)
{
    linked_list_t *tmp = NULL;
    tmp = this->head;

    while (tmp && !this->error) {
        if (tmp->str_data[0][0] == 'A')
            this->cnt_planes++;
        if (tmp->str_data[0][0] == 'T')
            this->cnt_towers++;
        tmp = tmp->next;
    }
}

static void open_n_read_file(ParseClass *this, char **argv)
{
    char *buffer;
    size_t bytes_read;
    FILE *file = fopen(argv[1], "r");

    buffer = malloc(sizeof(char) * 1000 + 1);
    bytes_read = fread(buffer, 1, 1000, file);
    fclose(file);
    if (bytes_read == 0) {
        my_putstr_stderr("Error reading file\n");
    }
    this->info_splitted = my_split(buffer, '\n');
}

static bool init_list(ParseClass *this, char **argv)
{
    int i = 0;
    open_n_read_file(this, argv);
    error_handling_parsing(this);
    linked_list_t *tmp = malloc(sizeof(linked_list_t));
    this->head = tmp;
    this->head->next = NULL;

    while (this->info_splitted[i] && !this->error) {
        tmp->str_data = my_split(this->info_splitted[i], ' ');
        if (!this->info_splitted[i + 1])
            tmp->next = NULL;
        else
            tmp->next = malloc(sizeof(linked_list_t));
        tmp = tmp->next;
        i++;
    }
    if (this->error)
        return (false);
    return (true);
}

static void parse_constructor(ParseClass *this)
{
    this = malloc(sizeof(ParseClass));
    this->head = NULL;
}

static void parse_destructor(ParseClass *this)
{
    free(this->head);
}

static const ParseClass description = {
        {
                .size = sizeof(ParseClass),
                .constructor = (constructor)&parse_constructor,
                .destructor = (destructor)&parse_destructor,
        },
        .head = NULL,
        .Init_list = &init_list,
        .count_objects = &count_objects,
        .error = false,
};

const Class *Parse = (const Class *)&description;
