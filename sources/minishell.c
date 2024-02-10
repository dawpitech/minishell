/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell header
*/

#include "../include/minishell.h"
#include "../include/env_manager.h"
#include "../include/prompt.h"

static
int initialize_shell(context_t *context, char **env)
{
    if (parse_source_env_var(context, env) == EXIT_FAILURE_TECH)
        return EXIT_FAILURE_TECH;
    context->running = true;
    return EXIT_SUCCESS_TECH;
}

static
void exiting_hook(context_t *context)
{
    free_env_var(context);
}

int minishell(__attribute__((unused)) int argc,
    __attribute__((unused)) char **argv, char **env)
{
    context_t context = {0};
    int rt_value;

    if (initialize_shell(&context, env) != EXIT_SUCCESS_TECH)
        return EXIT_FAILURE_TECH;
    while (context.running) {
        rt_value = launch_prompt(&context);
        if (rt_value != EXIT_SUCCESS_TECH)
            break;
    }
    exiting_hook(&context);
    return rt_value;
}
