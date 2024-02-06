/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** exit_cmd header
*/

#include <stddef.h>

#include "exit_cmd.h"
#include "my_printf.h"

int execute_exit(context_t *context)
{
    context->running = false;
    return EXIT_SUCCESS_TECH;
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
