/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** exit_cmd header
*/

#ifndef MINISHELL_BUILTINS_CMD_H
    #define MINISHELL_BUILTINS_CMD_H
    #include "minishell.h"
int execute_exit(context_t *context);
int execute_env(context_t *context);
int execute_setenv(context_t *context);
int execute_unsetenv(context_t *context);
#endif //MINISHELL_BUILTINS_CMD_H
