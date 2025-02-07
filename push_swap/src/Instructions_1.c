
#include "../include/push_swap.h"

void	pb(t_piles *pile, int bonus)
{
	int	i;

	if (pile->size_a)
	{
		pile->size_b++;
		i = pile->size_b;
		while (--i > 0)
			pile->b[i] = pile->b[i - 1];
		pile->b[0] = pile->a[0];
		i = -1;
		pile->size_a--;
		while (++i < pile->size_a)
			pile->a[i] = pile->a[i + 1];
		if (!bonus)
			write(1, "pb\n", 3);
	}
	else
		return ;
}

void	pa(t_piles *pile, int bonus)
{
	int	i;

	if (pile->size_b)
	{
		pile->size_a++;
		i = pile->size_a;
		while (--i > 0)
			pile->a[i] = pile->a[i - 1];
		pile->a[0] = pile->b[0];
		i = -1;
		pile->size_b--;
		while (++i < pile->size_b)
			pile->b[i] = pile->b[i + 1];
		if (!bonus)
			write(1, "pa\n", 3);
	}
	else
		return ;
}
