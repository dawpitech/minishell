/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_put_stderr header
*/

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "my_put_stderr.h"
#include "minishell.h"
#include "my.h"

int print_error_with_input(char *input)
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

ssize_t my_put_stderr(char const *str)
{
    return write(2, str, my_strlen(str));
}
