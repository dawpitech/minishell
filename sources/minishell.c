/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell header
*/

#include <unistd.h>
#include "../include/minishell.h"
#include "../include/env_manager.h"
#include "../include/prompt.h"

static
int initialize_shell(shell_t *shell, char **env)
{
    if (parse_source_env_var(shell, env) == RET_ERROR)
        return RET_ERROR;
    shell->running = true;
    shell->isatty = isatty(STDIN_FILENO);
    return RET_VALID;
}

static
void exiting_hook(shell_t *context)
{
    free_env_var(context);
}

int minishell(__attribute__((unused)) int argc,
    __attribute__((unused)) char **argv, char **env)
{
    shell_t shell = {0};

    if (initialize_shell(&shell, env) != EXIT_SUCCESS_TECH)
        return EXIT_FAILURE_TECH;
    while (shell.running)
        launch_prompt(&shell);
    exiting_hook(&shell);
    return EXIT_SUCCESS_TECH;
}
