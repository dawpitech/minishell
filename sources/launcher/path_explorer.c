/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** path_explorer header
*/

#include <malloc.h>

#include "../../include/path_explorer.h"
#include "../../include/env_manager.h"
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include "../../include/str_toolbox.h"

char *search_bin(shell_t *context)
{
    char *path = my_strdup(get_env_var(context, "PATH")->value);
    char *result = my_strtok(path, ':');

    while (result != NULL) {
        my_printf("Need to scan folder: %s\n", result);
        result = my_strtok(NULL, ':');
    }
    free(path);
    return NULL;
}
