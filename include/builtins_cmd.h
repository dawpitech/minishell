/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** exit_cmd header
*/

#ifndef MINISHELL_BUILTINS_CMD_H
    #define MINISHELL_BUILTINS_CMD_H
    #include "minishell.h"
int execute_exit(shell_t *context);
int execute_env(shell_t *context);
int execute_setenv(shell_t *context);
int execute_unsetenv(shell_t *context);
#endif //MINISHELL_BUILTINS_CMD_H
