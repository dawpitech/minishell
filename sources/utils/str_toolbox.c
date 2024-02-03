/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** str_toolbox header
*/

#include <stddef.h>

#include "str_toolbox.h"

char *my_strtok(char *str, char separator)
{
    static int current_index = 0;
    char *begin_of_str = &(str[current_index]);

    if (str == NULL || str[current_index] == '\0')
        return NULL;
    while (str[current_index] != '\0') {
        if (str[current_index] == separator) {
            str[current_index] = '\0';
            current_index += 1;
            return begin_of_str;
        }
        current_index += 1;
    }
    return begin_of_str;
}
