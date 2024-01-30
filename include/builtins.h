/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** builtins header
*/

#ifndef MINISHELL_BUILTINS_H
    #define MINISHELL_BUILTINS_H
    #include <stddef.h>

    #include "exit_cmd.h"

typedef struct {
    char *cmd;
    int (*fptr)(void);
} builtin_t;
static const builtin_t builtins_list[] = {
    {.cmd = "exit", .fptr = execute_exit},
    {.cmd = NULL, .fptr = NULL}
};
#endif //MINISHELL_BUILTINS_H
