/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_parser header
*/

#include "my_parser.h"
#include "builtins.h"
#include "builtins_runner.h"
#include "mem_toolbox.h"
#include "my_printf.h"
#include "str_toolbox.h"
#include <malloc.h>

static
char **parse_args(char *input)
{
    int nb_of_args = 1;
    char *arg = my_strtok(input, ' ');
    char **args = malloc(sizeof(char *) * nb_of_args);

    do {
        args = my_realloc(args, sizeof(char *) * (nb_of_args + 1),
            sizeof(char *) * (nb_of_args));
        args[nb_of_args - 1] = arg;
        nb_of_args += 1;
        arg = my_strtok(NULL, ' ');
    } while(arg != NULL);
    args[nb_of_args - 1] = NULL;
    return args;
}

int parse_input(context_t *context, char *input)
{
    int rt_value;

    context->args = parse_args(input);
    if (context->args == NULL || context->args[0] == NULL) {
        free(context->args);
        return EXIT_FAILURE_TECH;
    }
    rt_value = search_and_run_builtins(context, context->args[0]);
    free(context->args);
    context->args = NULL;
    if (rt_value != NO_CMD_FOUND)
        return rt_value;
    return EXIT_SUCCESS_TECH;
}
