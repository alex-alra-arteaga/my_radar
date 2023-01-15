/*
** EPITECH PROJECT, 2022
** My_Radar
** File description:
** The air traffic control panel
*/

#include "../../../includes/my.h"
#include "../../../includes/manage_files.h"
#include "../../../includes/manage_files_utils.h"

void check_info_splitted(ParseClass *this, char* info_splitted_0)
{
    if (info_splitted_0[0] != 'A' && info_splitted_0[0] != 'T'
    && !this->error) {
        my_putstr_stderr("Incorrect info parsing\n");
        this->error = true;
    }
}

void check_info_splitted_length
(ParseClass *this, char** info_splitted, int j, int c)
{
    while (info_splitted[j++]) {

    }
    if (info_splitted[0][0] == 'A' && !this->error) {
        if (j != 8) {
            my_putstr_stderr("Incorrect number of arguments for aircraft\n");
            this->error = true;
        }
    }
    if (info_splitted[0][0] == 'T' && !this->error) {
        while (info_splitted[c++]) {

        }
        if (c != 5 && !this->error) {
            my_putstr_stderr("Incorrect number of arguments for tower\n");
            this->error = true;
        }
    }
}

void check_type(ParseClass *this, char **info_splitted, int i, int k)
{
    if (!is_num(info_splitted[i][k]))
        this->error = true;
}

void check_info_splitted_values(ParseClass *this, char **info_splitted)
{
    for (int i = 1; info_splitted[i] && !this->error; ++i) {
        for (int k = 0; info_splitted[i][k]; k++) {
            check_type(this, info_splitted, i, k);
        }
    }
}

void error_handling_parsing(ParseClass *this)
{
    int j;
    int c;
    char **info_splitted;
    for (int cnt = 0; this->info_splitted[cnt] && !this->error; cnt++) {
        c = 0;
        j = 0;
        info_splitted = my_split(this->info_splitted[cnt], ' ');
        check_info_splitted(this, info_splitted[0]);
        check_info_splitted_length(this, info_splitted, j, c);
        check_info_splitted_values(this, info_splitted);
    }
}
