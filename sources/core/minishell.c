/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell header
*/

#include <malloc.h>
#include <stddef.h>
#include <stdio.h>

#include "minishell.h"
#include "hashtable.h"
#include "mem_toolbox.h"
#include "my.h"
#include "my_parser.h"
#include "my_printf.h"
#include "str_toolbox.h"

static
char *get_from_stdin(void)
{
    char *line = NULL;
    size_t buff_value = 0;
    int rt_value;

    rt_value = (int) getline(&line, &buff_value, stdin);
    if (rt_value <= 0) {
        free(line);
        return NULL;
    }
    line[my_strlen(line) - 1] = '\0';
    return line;
}

static
hashtable_t *parse_env(char **env)
{
    hashtable_t *ht = new_hashtable(hash, 25);

    for (int i = 0; env[i] != NULL; i += 1) {
        break;
    }
    return ht;
}

int minishell(int argc, char **argv, char **env)
{
    char *path = NULL;
    char *path_data;

    for (int i = 0; env[i] != NULL && path == NULL; i += 1) {
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            path = my_strdup(env[i] + 5);
    }
    if (path == NULL)
        my_put_stderr("Error: couldn't find path in env vars.");
    path_data = my_strtok(path, ':');
    while (path_data != NULL) {
        my_printf("%s\n", path_data);
        path_data = my_strtok(path, ':');
    }
    free(path);
    return 0;
}
