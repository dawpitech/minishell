/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** prompt header
*/

#include <malloc.h>
#include <stddef.h>

#include "../../include/prompt.h"
#include "../../include/my.h"
#include "../../include/my_parser.h"
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

int launch_prompt(context_t *context)
{
    char *command;

    my_printf("> $ ");
    command = get_from_stdin();
    parse_input(context, command);
    return EXIT_SUCCESS_TECH;
}
