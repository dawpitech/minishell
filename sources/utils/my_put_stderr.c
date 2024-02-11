/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_put_stderr header
*/

#include <unistd.h>

#include "my_put_stderr.h"
#include "../../include/my.h"

ssize_t my_put_stderr(char const *str)
{
    return write(2, str, my_strlen(str));
}
