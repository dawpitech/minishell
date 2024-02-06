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
    static char *current_str = NULL;
    char *begin_of_str;

    if (str != NULL)
        current_str = str;
    if (current_str == NULL || *current_str == '\0')
        return NULL;
    while (*current_str == separator)
        current_str += 1;
    begin_of_str = current_str;
    while (*current_str != '\0' && *current_str != separator)
        current_str += 1;
    if (*current_str != '\0') {
        *current_str = '\0';
        current_str += 1;
    }
    return begin_of_str;
}
