/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** exit_cmd header
*/

#ifndef MINISHELL_BUILTINS_CMD_H
    #define MINISHELL_BUILTINS_CMD_H
    #include "minishell.h"
int execute_cd(shell_t *shell, int argc, char **argv);
int execute_exit(shell_t *shell, int argc, char **argv);
int execute_env(shell_t *shell, int argc, char **argv);
int execute_setenv(shell_t *shell, int argc, char **argv);
int execute_unsetenv(shell_t *shell, int argc, char **argv);
#endif //MINISHELL_BUILTINS_CMD_H
