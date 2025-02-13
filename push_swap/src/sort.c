#include "../include/push_swap.h"

void	temporary_sort(int *pile_temporaire, int size)
{
	int	i;
	int	j;
	int	temporaire;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (pile_temporaire[i] > pile_temporaire[j])
			{
				temporaire = pile_temporaire[i];
				pile_temporaire[i] = pile_temporaire[j];
				pile_temporaire[j] = temporaire;
			}
			j++;
		}
		i++;
	}
}

void	three_numbers_case_pile_a(t_piles *three)
{
	if (three->a[0] > three->a[1] && three->a[0] < three->a[2]
		&& three->a[1] < three->a[2])
		sa(three);
	if (three->a[0] > three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] > three->a[2])
	{
		sa(three);
		rra(three);
	}
	if (three->a[0] > three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] < three->a[2])
		ra(three);
	if (three->a[0] < three->a[1] && three->a[0] < three->a[2]
		&& three->a[1] > three->a[2])
	{
		sa(three);
		ra(three);
	}
	if (three->a[0] < three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] > three->a[2])
		rra(three);
}

int	sort(t_piles *pile, int size)
{
	if (check_sorted(pile->a, pile->size_a, 0) == 0)
	{
		if (size == 2)
			sa(pile);
		else if (size == 3)
			three_numbers_case_pile_a(pile);
		else
			quicksort_pile_a(pile, size, 0);
	}
	return (0);
}


