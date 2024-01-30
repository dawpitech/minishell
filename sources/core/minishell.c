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
#include "my.h"
#include "my_parser.h"
#include "my_printf.h"

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

int minishell(int argc, char **argv)
{
    char *input;

    while (1) {
        my_printf("> $ ");
        input = get_from_stdin();
        if (parse_input(input) == 1)
            break;
        free(input);
    }
    return 0;
}
