/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** builtins header
*/

#ifndef MINISHELL_BUILTINS_H
    #define MINISHELL_BUILTINS_H
    #define NO_CMD_FOUND 42
    #include <stddef.h>

    #include "exit_cmd.h"
    #include "minishell.h"
typedef struct {
    char *cmd;
    int (*fptr)(context_t *context);
} builtin_t;
static const builtin_t builtins_list[] = {
    {.cmd = "env", .fptr = execute_env},
    {.cmd = "exit", .fptr = execute_exit},
    {.cmd = NULL, .fptr = NULL}
};
#endif //MINISHELL_BUILTINS_H
