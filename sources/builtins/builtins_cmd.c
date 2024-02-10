/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** exit_cmd header
*/

#include <stddef.h>

#include "builtins_cmd.h"
#include "env_manager.h"
#include "my_printf.h"

static
int calculate_nb_args(context_t *context)
{
    int i;

    for (i = 0; context->args[i] != NULL; i += 1);
    return i;
}

int execute_exit(context_t *context)
{
    context->running = false;
    return EXIT_SUCCESS_TECH;
}

int execute_setenv(context_t *context)
{
    int argc = calculate_nb_args(context);

    if (argc < 3) {
        my_printf("Error: not enough arguments");
        return EXIT_FAILURE_TECH;
    }
    if (argc > 3) {
        my_printf("Error: too many arguments");
        return EXIT_FAILURE_TECH;
    }
    return add_env_var(context, context->args[1], context->args[2]);
}

int execute_env(context_t *context)
{
    env_var_t *curr = context->env_var;

    while (curr != NULL) {
        if (curr->value != NULL) {
            my_printf("%s=%s\n", curr->key, curr->value);
        } else {
            my_printf("%s=\n", curr->key);
        }
        curr = curr->next;
    }
    return EXIT_SUCCESS_TECH;
}
