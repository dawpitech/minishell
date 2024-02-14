/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** exit_cmd header
*/

#include <stddef.h>
#include <unistd.h>

#include "builtins_cmd.h"
#include "env_manager.h"
#include "my_printf.h"
#include "my_put_stderr.h"
#include "my.h"

static
int calculate_nb_args(shell_t *context)
{
    int i;

    for (i = 0; context->args[i] != NULL; i += 1);
    return i;
}

int execute_cd(shell_t *shell)
{
    char *new_path = malloc(sizeof(char) * (my_strlen(shell->current_path) + my_strlen(shell->args[1]) + 3));

    my_printf("Old: %s\n", shell->current_path);
    my_strcpy(new_path, shell->current_path);
    my_strcat(new_path, "/");
    my_strcat(new_path, shell->args[1]);
    my_printf("Computed: %s\n", new_path);
    chdir(new_path);
    free(new_path);
    free(shell->current_path);
    shell->current_path = getcwd(NULL, 0);
    my_printf("Current: %s\n", shell->current_path);
    return RET_VALID;
}

int execute_unsetenv(shell_t *shell)
{
    int argc = calculate_nb_args(shell);

    if (argc < 2) {
        my_put_stderr("unsetenv: Too few arguments.");
        return EXIT_FAILURE_TECH;
    }
    return remove_env_var(shell, shell->args[1]);
}

int execute_exit(shell_t *context)
{
    context->running = false;
    return EXIT_SUCCESS_TECH;
}

int execute_setenv(shell_t *shell)
{
    int argc = calculate_nb_args(shell);

    if (argc > 3) {
        my_put_stderr("setenv: Too many arguments.\n");
        return EXIT_FAILURE_TECH;
    }
    if (argc == 1)
        return execute_env(shell);
    if (argc == 2)
        return add_env_var(shell, shell->args[1], NULL);
    return add_env_var(shell, shell->args[1], shell->args[2]);
}

int execute_env(shell_t *context)
{
    env_var_t *curr = context->env_var;

    while (curr != NULL) {
        if (curr->value != NULL) {
            my_printf("%s=%s\n", curr->key, curr->value);
        } else {
            my_printf("%s=\n", curr->key);
        }
        curr = curr->next;
    }
    return EXIT_SUCCESS_TECH;
}
