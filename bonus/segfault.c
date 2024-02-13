/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** segfault header
*/

#include <stddef.h>
#include <stdio.h>

void main(void)
{
    printf("Going to segfault in 3.. 2.. 1..\n");
    int *ptr = NULL;

    *ptr = 42;
}
