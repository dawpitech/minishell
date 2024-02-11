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
#include "my.h"
#include "path_explorer.h"

int launch_bin(context_t *context)
{
    if (my_strstr(context->args[0], "/"))
        return launch_bin_by_path(context);
    return launch_bin_by_env_path(context);
}

int launch_bin_by_env_path(context_t *context)
{
    search_bin(context);
    return 0;
    // USE BELOW TO RUN BIN
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        execv("/usr/bin/env", context->args);
        exit(127);
    } else {
        waitpid(pid, 0, 0);
    }
    return EXIT_SUCCESS_TECH;
}

int launch_bin_by_path(context_t *context)
{
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        execv(context->args[0], context->args);
        exit(EXIT_FAILURE_TECH);
    } else
        waitpid(pid, 0, 0);
    return EXIT_SUCCESS_TECH;
}
