#include "../include/push_swap.h"

void	rra(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_a == 0 || pile->size_a == 1)
		return ;
	i = pile->size_a - 1;
	tmp = pile->a[i];
	while (i)
	{
		pile->a[i] = pile->a[i - 1];
		i--;
	}
	pile->a[i] = tmp;
	write(1, "rra\n", 4);

}

void	rrb(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_b == 0 || pile->size_b == 1)
		return ;
	i = pile->size_b - 1;
	tmp = pile->b[i];
	while (i)
	{
		pile->b[i] = pile->b[i - 1];
		i--;
	}
	pile->b[i] = tmp;
	write(1, "rrb\n", 4);

}

void	rrr(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_a == 0 || pile->size_a == 1
		|| (pile->size_b == 0 || pile->size_b == 1))
		return ;
	i = pile->size_a - 1;
	tmp = pile->a[i];
	while (i)
	{
		pile->a[i] = pile->a[i - 1];
		i--;
	}
	pile->a[i] = tmp;
	i = pile->size_b - 1;
	tmp = pile->b[i];
	while (i--)
		pile->b[i] = pile->b[i - 1];
	pile->b[i] = tmp;
	write(1, "rrr\n", 4);

}
