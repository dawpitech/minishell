/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** env_manager header
*/

#ifndef MINISHELL_ENV_MANAGER_H
    #define MINISHELL_ENV_MANAGER_H
    #include "minishell.h"
int add_env_var(context_t *context, char *key, char *value);
int parse_source_env_var(context_t *context, char **env);
void free_env_var(context_t *context);
int remove_env_var(context_t *context, char *key);
#endif //MINISHELL_ENV_MANAGER_H
