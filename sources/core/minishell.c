/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell header
*/

#include "minishell.h"
#include "env_manager.h"
#include "prompt.h"

int minishell(__attribute__((unused)) int argc,
    __attribute__((unused)) char **argv, char **env)
{
    context_t context = {0};

    if (parse_source_env_var(&context, env) == EXIT_FAILURE_TECH)
        return EXIT_FAILURE_TECH;
    context.running = true;
    while (context.running) {
        launch_prompt(&context);
    }
    return EXIT_SUCCESS_TECH;
}
