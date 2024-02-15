/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_parser header
*/

#include <malloc.h>

#include "my_parser.h"
#include "builtins.h"
#include "builtins_runner.h"
#include "launcher.h"
#include "mem_toolbox.h"
#include "my.h"
#include "my_printf.h"
#include "str_toolbox.h"

static
char **parse_args(char *input)
{
    int nb_of_args = 1;
    char *arg = my_strtok(input, ' ');
    char **args = malloc(sizeof(char *) * nb_of_args);

    do {
        args = realloc(args, sizeof(char *) * (nb_of_args + 1));
        args[nb_of_args - 1] = arg;
        nb_of_args += 1;
        arg = my_strdup(my_strtok(NULL, ' '));
    } while (arg != NULL);
    args[nb_of_args - 1] = NULL;
    return args;
}

static
int init_parser(shell_t *shell, char *input)
{
    shell->args = parse_args(input);
    if (shell->args == NULL || shell->args[0] == NULL) {
        free(shell->args);
        return shell->args == NULL ? RET_ERROR : RET_VALID;
    }
    return RET_VALID;
}

static
void clean_parser(shell_t *shell, int rt_value)
{
    for (int i = 0; shell->args[i] != NULL && rt_value != RET_ERROR; i += 1)
        free(shell->args[i]);
    free(shell->args);
}

int parse_input(shell_t *context)
{
    int rt_value;

    if (init_parser(context, input) == RET_ERROR)
        return RET_ERROR;
    rt_value = search_and_run_builtins(context, context->args[0]);
    if (rt_value == NO_CMD_FOUND) {
        rt_value = launch_bin(context);
    } else {
        clean_parser(context, rt_value);
        return rt_value;
    }
    if (rt_value == RET_ERROR) {
        my_put_stderr(context->args[0]);
        my_put_stderr(": Command not found.\n");
    }
    clean_parser(context, rt_value);
    return rt_value != NO_CMD_FOUND ? rt_value : EXIT_SUCCESS_TECH;
}
