/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** minishell header
*/

#ifndef MINISHELL_MINISHELL_H
    #define MINISHELL_MINISHELL_H
    #define EXIT_FAILURE_TECH 84
    #define EXIT_SUCCESS_TECH 0
    #define DEFAULT_LOG_LEVEL 6
    #include <stdbool.h>

    #include "hashtable.h"
int minishell(__attribute__((unused)) int argc,
    __attribute__((unused)) char **argv, char **env);
typedef struct env_var_s {
    char *key;
    char *value;
    struct env_var_s *next;
} env_var_t;
typedef struct {
    env_var_t *env_var;
    bool running;
    char **args;
} context_t;
#endif //MINISHELL_MINISHELL_H
