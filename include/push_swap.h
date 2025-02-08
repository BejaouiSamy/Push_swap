#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_piles
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_piles;

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

void	push_swap(char **av);
int		push_swap_len(char **av);
void	error_detected(int *pile);
int		push_swap_atoi(char *str, int *pile);
void	check_doubles(int *pile, int size);
//Instructions
void	sa(t_piles *pile);
void	sb(t_piles *pile);
void	ss(t_piles *pile);
void	ra(t_piles *pile);
void	rb(t_piles *pile);
void	rr(t_piles *pile);
void	rra(t_piles *pile);
void	rrb(t_piles *pile);
void	rrr(t_piles *pile);
void	pb(t_piles *pile);
void	pa(t_piles *pile);
//Sort
int		sort(t_piles *pile, int size);
int		check_sorted(int *pile, int size, int order);
void	three_numbers_case_pile_a(t_piles *three);
void	temporary_sort(int *pile_temporaire, int size);
//Quicksort
int		quicksort_pile_a(t_piles *pile, int len, int count_r);
int		quicksort_pile_b(t_piles *pile, int len, int count_r);
void	quicksort_three_pile_a_and_b(t_piles *pile, int len);
int		sort_three_b(t_piles *pile, int len);
int		ft_push(t_piles *pile, int len, int pb);
int		mediane_of_numbers(int *pivot, int *pile, int size);
#endif
