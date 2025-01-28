#include "push_swap.h"

void pa(t_stack *stack_a, t_stack *stack_b)
{
    int i;

    if(stack_b && stack_b->size > 0)
    {
        i = stack_a->size;
        while (i > 0)
        {
            stack_a->numbers[i] = stack_a->numbers[i - 1];
            i--;
        }
        stack_a->numbers[0] = stack_b->numbers[0];
        i = 0;
        while(i < stack_b->size - 1)
        {
            stack_b->numbers[i] = stack_b->numbers[i + 1];
            i++;
        }
        stack_a->size++;
        stack_b->size--;
        write(1, "pa\n", 3);
    }
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    int i;

    if (stack_a && stack_a->size > 0)
    {
        i = stack_b->size;
        while(i > 0)
        {
            stack_b->numbers[i] = stack_b->numbers[i - 1];
            i--;
        }
        stack_b->numbers[0] = stack_a->numbers[0];
        i = 0;
        while (i < stack_a->size - 1)
        {
            stack_a->numbers[i] = stack_a->numbers[i + 1];
            i++;
        }
        stack_b->size++;
        stack_a->size--;
        write(1, "pb\n", 3);
    }
}