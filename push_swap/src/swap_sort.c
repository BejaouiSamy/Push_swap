#include "push_swap.h"

// Swap les 2 premiers elements de la pile A
void sa(t_stack *stack_a)
{
    if (stack_a && stack_a->size >= 2)
    {
        ft_swap(&stack_a->numbers[0], &stack_a->numbers[1]);
        write(1, "sa\n", 3);
    }
}

// Swap les 2 premiers elements de la pile B
void sb(t_stack *stack_b)
{
    if (stack_b && stack_b->size >= 2)
    {
        ft_swap(&stack_b->numbers[0], &stack_b->numbers[1]);
        write(1, "sb\n", 3);
    }
}

// sa et sb en meme temps
void ss(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a && stack_b
        && stack_a->size >= 2 && stack_b->size >= 2)
    {
        swap(&stack_a->numbers[0], &stack_a->numbers[1]);
        swap(&stack_b->numbers[0], &stack_b->numbers[1]);
        write(1, "ss\n", 3);
    }
}