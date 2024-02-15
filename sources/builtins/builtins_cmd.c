/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** exit_cmd header
*/

#include <errno.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

#include "builtins_cmd.h"
#include "env_manager.h"
#include "my.h"
#include "my_printf.h"

static
int calculate_nb_args(shell_t *context)
{
    int i;

    for (i = 0; context->args[i] != NULL; i += 1);
    return i;
}

static
char *compute_cd_path(shell_t *shell)
{
    env_var_t *home_var = get_env_var(shell, "HOME");

    if (my_strcmp(shell->args[1], "-") == 0)
        return shell->last_path == NULL ? "\0" : my_strdup(shell->last_path);
    if (my_strcmp(shell->args[1], "~") == 0) {
        if (home_var != NULL)
            return my_strdup(home_var->value);
        my_put_stderr("Ho $home variable set.\n");
        return NULL;
    }
    return my_strdup(shell->args[1]);
}

static
int print_cd_error(char *input)
{
    if (input[0] != '\0') {
        my_put_stderr(input);
        free(input);
    }
    my_put_stderr(": ");
    my_put_stderr(strerror(errno));
    my_put_stderr(".\n");
    return RET_ERROR;
}

static
void update_shell_ref(shell_t *shell, char *new_path, char *old_path)
{
    free(new_path);
    free(shell->current_path);
    shell->current_path = getcwd(NULL, 0);
    if (shell->last_path != NULL)
        free(shell->last_path);
    shell->last_path = old_path;
}

int execute_cd(shell_t *shell)
{
    int rt_val;
    char *new_path = compute_cd_path(shell);
    char *old_path = getcwd(NULL, 0);

    if (new_path == NULL)
        return RET_ERROR;
    errno = 0;
    rt_val = chdir(new_path);
    if (rt_val == -1)
        return print_cd_error(new_path);
    update_shell_ref(shell, new_path, old_path);
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
