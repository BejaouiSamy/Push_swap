#include "../include/push_swap.h"

void	ra(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_a == 0 || pile->size_a == 1)
		return ;
	i = 0;
	tmp = pile->a[i];
	i++;
	while (i < pile->size_a)
	{
		pile->a[i - 1] = pile->a[i];
		i++;
	}
	pile->a[i - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_b == 0 || pile->size_b == 1)
		return ;
	i = 0;
	tmp = pile->b[i];
	i++;
	while (i < pile->size_b)
	{
		pile->b[i - 1] = pile->b[i];
		i++;
	}
	pile->b[i - 1] = tmp;
	write(1, "rb\n", 3);

}

void	rr(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_a == 0 || pile->size_a == 1
		|| (pile->size_b == 0 || pile->size_b == 1))
		return ;
	i = 0;
	tmp = pile->a[i];
	while (++i < pile->size_a)
		pile->a[i - 1] = pile->a[i];
	pile->a[i - 1] = tmp;
	i = 0;
	tmp = pile->b[i];
	while (++i < pile->size_b)
		pile->b[i - 1] = pile->b[i];
	pile->b[i - 1] = tmp;
	write(1, "rr\n", 3);

}
