#include "../include/push_swap.h"

void	sa(t_piles *pile, int bonus)
{
	int	tmp;

	if (pile->size_a == 0 || pile->size_a == 1)
		return ;
	tmp = 0;
	tmp = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = tmp;
	if (!bonus)
		write(1, "sa\n", 3);

}

void	sb(t_piles *pile, int bonus)
{
	int	tmp;

	if (pile->size_b == 0 || pile->size_b == 1)
		return ;
	tmp = 0;
	tmp = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = tmp;
	if (!bonus)
		write(1, "sb\n", 3);

}

void	ss(t_piles *pile, int bonus)
{
	int	tmp;

	if (pile->size_a == 0 || pile->size_a == 1
		|| (pile->size_b == 0 || pile->size_b == 1))
		return ;
	tmp = 0;
	tmp = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = tmp;
	tmp = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = tmp;
	if (!bonus)
		write(1, "ss\n", 3);

}