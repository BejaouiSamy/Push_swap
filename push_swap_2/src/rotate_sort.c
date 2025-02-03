#include "push_swap.h"

// Rotate a - decale d'une position vers le haut tous les elements de A
void ra(t_stack *stack_a)
{
    int temp;
    int i;

    if (stack_a && stack_a->size > 1)
    {
        temp = stack_a->numbers[0];
        i = 0;
        while (i < stack_a->size - 1)
        {
            stack_a->numbers[i] = stack_a->numbers[i + 1];
            i++;
        }
        stack_a->numbers[stack_a->size - 1] = temp;
        write(1, "ra\n", 3);
    }
}

// Rotate b - decale d'une position vers le haut tous les elements de B
void rb(t_stack *stack_b)
{
    int temp;
    int i;

    if (stack_b && stack_b->numbers[0])
    {
        temp = stack_b->numbers[0];
        i = 0;
        while (i < stack_b->size - 1)
        {
            stack_b->numbers[i] = stack_b->numbers[i + 1];
            i++;
        }
        stack_b->numbers[stack_b->size - 1] = temp;
        write(1, "rb\n", 3);
    }
}

// ra et rb en meme temps
void rr(t_stack *stack_a, t_stack *stack_b)
{
    int temp;
    int i;

    if (stack_a && stack_b
        && stack_a->size > 1 && stack_b->size > 1)
    {
        temp = stack_a->numbers[0];
        i = 0;
        // Rotate A
        while (i < stack_a->size - 1)
        {
            stack_a->numbers[i] = stack_a->numbers[i + 1];
            i++;
        }
        stack_a->numbers[stack_a->size - 1] = temp;
        temp = stack_b->numbers[0];
        i = 0;
        while (i < stack_b->size - 1)
        {
            stack_b->numbers[i] = stack_b->numbers[i + 1];
            i++;
        }
        stack_b->numbers[stack_b->size - 1] = temp;
        write(1, "rr\n", 3);
    }
}

void smart_rotate(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
    while (pos_a > 0 && pos_b > 0)
    {
        rr(a, b);
        pos_a--;
        pos_b--;
    }
    while (pos_a > 0)
    {
        ra(a);
        pos_a--;
    }
    while (pos_b > 0)
    {
        rb(b);
        pos_b--;
    }
    
}