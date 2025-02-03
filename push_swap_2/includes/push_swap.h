#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define NB_CHUNKS 7
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_stack {
    int *numbers;
    int size;
    int capacity;
}   t_stack;

int find_min(t_stack *stack, int start, int size);
int find_position(t_stack *stack, int num);
void bring_to_top(t_stack *stack, int pos);
void merge_sort(t_stack *a, t_stack *b);
t_stack *init_stack(int size);
int	ft_isdigit(int c);
int is_int(const char *str);
int is_duplicated(int *nums, int size);
t_stack *create_stack(int size);
void free_stack(t_stack *stack);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);
void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void find_chunks_limits(t_stack *a, int *chunks, int nb_chunks);
int find_best_push(t_stack *a, int chunk_min, int chunk_max);
void turk_sort(t_stack *a, t_stack *b);
int find_max(t_stack *stack);
void smart_rotate(t_stack *a, t_stack *b, int pos_a, int pos_b);
int find_target_position(t_stack *b, int num);

# endif