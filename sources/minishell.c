/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell header
*/

#include <unistd.h>
#include <stdio.h>

#include "../include/minishell.h"
#include "../include/env_manager.h"
#include "../include/my_parser.h"
#include "../include/prompt.h"
#include "../include/runner.h"

static
int initialize_shell(shell_t *shell, char **env)
{
    if (parse_env_var(shell, env) == RET_ERROR)
        return RET_ERROR;
    shell->running = true;
    shell->isatty = isatty(STDIN_FILENO);
    shell->current_path = getcwd(NULL, 0);
    shell->last_path = NULL;
    shell->last_exit_code = 0;
    return RET_VALID;
}

static
void exiting_hook(shell_t *shell)
{
    free(shell->current_path);
    if (shell->last_path != NULL)
        free(shell->last_path);
    free_env_var(shell);
}

static
void clean_prompt(shell_t *shell)
{
    for (int i = 0; shell->prompt->argv[i] != NULL; i += 1)
        free(shell->prompt->argv[i]);
    free(shell->prompt->argv);
    free(shell->prompt->raw_input);
    free(shell->prompt);
}

int minishell(__attribute__((unused)) int argc,
    __attribute__((unused)) char **argv, char **env)
{
    shell_t shell = {0};

    if (initialize_shell(&shell, env) != EXIT_SUCCESS_TECH)
        return EXIT_FAILURE_TECH;
    while (shell.running) {
        if (present_prompt(&shell) == RET_ERROR)
            break;
        if (parse_input(&shell) == RET_ERROR)
            break;
        shell.last_exit_code = run_command(&shell);
        clean_prompt(&shell);
    }
    exiting_hook(&shell);
    return shell.last_exit_code;
}
