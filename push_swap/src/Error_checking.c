#include "push_swap.h"

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