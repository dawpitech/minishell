/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** Return 1 if the number is prime, 0 if not
*/

int my_is_prime(int nb)
{
    if (nb < 2) {
        return 0;
    }
    for (int i = 2; i < nb; i += 1) {
        if (nb % i == 0) {
            return (0);
        }
    }
    return (1);
}
