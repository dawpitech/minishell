/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** launcher header
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#include "launcher.h"
#include "env_converter.h"
#include "my.h"
#include "path_explorer.h"
#include "my_printf.h"

int launch_bin(shell_t *context)
{
    if (my_strstr(context->args[0], "/"))
        return launch_bin_by_path(context);
    return launch_bin_by_env_path(context);
}

int launch_bin_by_env_path(shell_t *shell)
{
    char *full_path;
    char *bin_loc = search_bin(shell);
    int rt_value;

    if (bin_loc == NULL)
        return RET_ERROR;
    full_path = malloc(sizeof(char) * (my_strlen(bin_loc) + my_strlen(shell->args[0]) + 2));
    if (full_path == NULL)
        return RET_ERROR;
    my_strcpy(full_path, bin_loc);
    my_strcat(full_path, "/");
    my_strcat(full_path, shell->args[0]);
    shell->args[0] = full_path;
    rt_value = launch_bin_by_path(shell);
    free(full_path);
    return rt_value;
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
    }
    waitpid(pid, 0, 0);
    free_env_array(env);
    return EXIT_SUCCESS_TECH;
}
