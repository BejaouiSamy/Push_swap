#include <limits.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


int is_int(const char *str)
{
    long long result;
    int sign;

    sign = 1;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (*str == '\0')
        return (0);
    result = 0;
    while(*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        result = result * 10 + (*str - '0');
        if (result * sign > INT_MAX || result * sign < INT_MIN)
            return (0);
        str++;
    }
    return (1);
}

int is_duplicated(int *nums, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (nums[i] == nums[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
    if (ac < 2) // Pas assez d'arguments
    {
        printf("Error: no arguments provided.\n");
        return (1);
    }

    int *numbers = malloc((ac - 1) * sizeof(int));
    if (!numbers) // Vérifie l'allocation mémoire
    {
        printf("Error: memory allocation failed.\n");
        return (1);
    }

    for (int i = 1; i < ac; i++)
    {
        if (!is_int(av[i])) // Vérifie chaque argument
        {
            printf("Error: invalid argument '%s'.\n", av[i]);
            free(numbers);
            return (1);
        }
        numbers[i - 1] = atoi(av[i]);
    }

    if (is_duplicated(numbers, ac - 1)) // Vérifie les doublons
    {
        printf("Error: duplicate values found.\n");
        free(numbers);
        return (1);
    }

    // Si tout est valide
    printf("All arguments are valid.\n");

    // Libération de la mémoire
    free(numbers);
    return (0);
}