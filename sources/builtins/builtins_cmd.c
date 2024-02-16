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
char *compute_cd_path(shell_t *shell, char **argv)
{
    env_var_t *home_var = get_env_var(shell, "HOME");

    if (my_strcmp(argv[1], "-") == 0)
        return shell->last_path == NULL ? "\0" : my_strdup(shell->last_path);
    if (my_strcmp(argv[1], "~") == 0) {
        if (home_var != NULL)
            return my_strdup(home_var->value);
        my_put_stderr("No $home variable set.\n");
        return NULL;
    }
    return my_strdup(argv[1]);
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

int execute_cd(shell_t *shell, __attribute__((unused)) int argc, char **argv)
{
    int rt_val;
    char *new_path = compute_cd_path(shell, argv);
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

int execute_unsetenv(shell_t *shell, int argc, char **argv)
{
    if (argc < 2) {
        my_put_stderr("unsetenv: Too few arguments.");
        return 1;
    }
    for (int i = 1; i < argc; i += 1)
        remove_env_var(shell, argv[i]);
    return 0;
}

int execute_exit(shell_t *shell, __attribute__((unused)) int argc,
    __attribute__((unused)) char **argv)
{
    shell->running = false;
    return EXIT_SUCCESS_TECH;
}

int execute_setenv(shell_t *shell, int argc, char **argv)
{
    if (argc > 3) {
        my_put_stderr("setenv: Too many arguments.\n");
        return EXIT_FAILURE_TECH;
    }
    if (argc == 1)
        return execute_env(shell, argc, argv);
    if (argc == 2)
        return add_env_var(shell, argv[1], NULL);
    return add_env_var(shell, argv[1], argv[2]);
}

int execute_env(shell_t *shell, __attribute__((unused)) int argc,
    __attribute__((unused)) char **argv)
{
    env_var_t *curr = shell->env_var;

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
