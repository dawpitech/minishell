/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** launcher header
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "launcher.h"
#include "env_converter.h"
#include "my.h"
#include "path_explorer.h"

int launch_bin(shell_t *context)
{
    if (my_strstr(context->args[0], "/"))
        return launch_bin_by_path(context);
    return launch_bin_by_env_path(context);
}

int launch_bin_by_env_path(shell_t *context)
{
    search_bin(context);
    return 0;
}

int launch_bin_by_path(shell_t *shell)
{
    pid_t pid;
    char **env;

    env = get_env_array(shell);
    pid = fork();
    if (pid == 0) {
        execve(shell->args[0], shell->args, env);
        exit(EXIT_FAILURE_TECH);
    } else
        waitpid(pid, 0, 0);
    free_env_array(env);
    return EXIT_SUCCESS_TECH;
}
