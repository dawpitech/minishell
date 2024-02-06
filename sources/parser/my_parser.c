/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_parser header
*/

#include "my_parser.h"
#include "builtins.h"
#include "builtins_runner.h"

int parse_input(context_t *context, char *input)
{
    int rt_value;

    rt_value = search_and_run_builtins(context, input);
    if (rt_value != NO_CMD_FOUND)
        return rt_value;
    return EXIT_SUCCESS_TECH;
}
