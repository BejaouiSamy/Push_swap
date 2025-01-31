#include "push_swap.h"

// Reverse rotate A - decale d'une position vers le bas tous les elements A
void rra(t_stack *stack_a)
{  
    int temp;
    int i;

    if (!stack_a || stack_a->size <= 1
        || stack_a->size > stack_a->capacity)
        return;
    if (stack_a && stack_a->size > 1)
    {
        temp = stack_a->numbers[stack_a->size - 1];
        i = stack_a->size - 1;
        while (i > 0)
        {
            stack_a->numbers[i] = stack_a->numbers[i - 1];
            i--;
        }
        stack_a->numbers[0] = temp;
        write(1, "rra\n", 4);
    }
}

// Reverse rotate B - decale d'une position vers le bas tous les elements B
void rrb(t_stack *stack_b)
{
    int temp;
    int i;

    if (stack_b && stack_b->size > 1)
    {
        temp = stack_b->numbers[stack_b->size - 1];
        i = stack_b->size - 1;
        while (i > 0)
        {
            stack_b->numbers[i] = stack_b->numbers[i - 1]; 
            i--;
        }
        stack_b->numbers[0] = temp;
        write(1, "rrb\n", 4);
    }
}

// rra et rrb en meme temps
void rrr(t_stack *stack_a, t_stack *stack_b)
{
    int temp;
    int i;

    if (stack_a && stack_b
        && stack_a->size > 1 && stack_b->size > 1)
    {
        temp = stack_a->numbers[stack_a->size - 1];
        i = stack_a->size - 1;
        while (i > 0)
        {
            stack_a->numbers[i] = stack_a->numbers[i - 1];
            i--;
        }
        stack_a->numbers[0] = temp;
        temp = stack_b->numbers[stack_b->size - 1];
        i = stack_b->size - 1;
        while (i > 0)
        {
            stack_b->numbers[i] = stack_b->numbers[i - 1];
            i--;
        }
        stack_b->numbers[0] = temp;
        write (1, "rrr\n", 4);
    }
}