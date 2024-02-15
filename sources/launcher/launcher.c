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

int launch_bin(shell_t *shell)
{
    int argc = shell->prompt->argc;
    char **argv = shell->prompt->argv;

    if (my_strstr(argv[0], "/"))
        return launch_bin_by_path(shell, argc, argv);
    return launch_bin_by_env_path(shell, argc, argv);
}

int launch_bin_by_env_path(shell_t *shell, int argc, char **argv)
{
    char *full_path;
    char *bin_loc = search_bin(shell);
    int rt_value;

    if (bin_loc == NULL)
        return RET_ERROR;
    full_path = malloc(sizeof(char) * (my_strlen(bin_loc)
        + my_strlen(argv[0]) + 2));
    if (full_path == NULL)
        return RET_ERROR;
    my_strcpy(full_path, bin_loc);
    my_strcat(full_path, "/");
    my_strcat(full_path, argv[0]);
    argv[0] = full_path;
    rt_value = launch_bin_by_path(shell, argc, argv);
    free(bin_loc);
    return rt_value;
}

int launch_bin_by_path(shell_t *shell, int argc, char **argv)
{
    pid_t pid;
    char **env;
    int child_status;

    env = get_env_array(shell);
    pid = fork();
    if (pid == 0) {
        execve(argv[0],argv, env);
        return RET_ERROR;
    }
    waitpid(pid, &child_status, 0);
    if (WIFSIGNALED(child_status) && WTERMSIG(child_status) == SIGSEGV) {
        my_put_stderr("Segmentation fault");
        if (WCOREDUMP(child_status))
            my_put_stderr(" (core dumped)");
        my_put_stderr("\n");
    }
    free_env_array(env);
    return EXIT_SUCCESS_TECH;
}
