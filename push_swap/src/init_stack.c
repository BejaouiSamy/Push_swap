#include "push_swap.h"

/*
// Fonction pour initialiser une pile
t_stack *init_stack(int size)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    stack->numbers = (int *)malloc(sizeof(int) * size);
    if (!stack->numbers)
    {
        free(stack);
        return NULL;
    }
    stack->size = size;
    stack->top = -1;
    return (stack);
}*/

// Fonction utilitaire pour creer une nouvelle pile
t_stack *create_stack(int size)
{
    t_stack *stack;
    
    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    stack->numbers = (int *)malloc(sizeof(int) * size);
    if (!stack->numbers)
    {
        free(stack);
        return NULL;
    }
    stack->size = 0;
    return (stack);
}

// Fonction pour liberer une pile
void free_stack(t_stack *stack)
{
    if (stack)
    {
        if (stack->numbers)
            free (stack->numbers);
        free(stack);
    }
}