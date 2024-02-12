/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** launcher header
*/

#ifndef MINISHELL_LAUNCHER_H
    #define MINISHELL_LAUNCHER_H
    #include "minishell.h"
int launch_bin(shell_t *context);
int launch_bin_by_env_path(shell_t *context);
int launch_bin_by_path(shell_t *shell);
#endif //MINISHELL_LAUNCHER_H
