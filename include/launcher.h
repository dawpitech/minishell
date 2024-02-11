/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** launcher header
*/

#ifndef MINISHELL_LAUNCHER_H
    #define MINISHELL_LAUNCHER_H
    #include "minishell.h"
int launch_bin(context_t *context);
int launch_bin_by_env_path(context_t *context);
int launch_bin_by_path(context_t *context);
#endif //MINISHELL_LAUNCHER_H
