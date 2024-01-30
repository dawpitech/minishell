/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_parser header
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "my_parser.h"
#include "builtins.h"
#include "my.h"

int parse_input(char *input)
{
    for (int i = 0; builtins_list[i].cmd != NULL; i += 1) {
        if (my_strcmp(builtins_list[i].cmd, input) == 0) {
            return builtins_list[i].fptr();
        }
    }
    pid_t pid = fork();
    if (pid == 0) {
        static char *argv[]={"ls", NULL};
        execv("/usr/bin/env", argv);
        exit(127);
    } else {
        waitpid(pid, 0, 0);
    }
    return 0;
}
