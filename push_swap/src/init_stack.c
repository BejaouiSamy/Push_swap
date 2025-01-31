#include "push_swap.h"
#include <stdio.h>


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
    stack->capacity = size;
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

void print_stack(t_stack *stack)
{
    int i;

    i = 0;
    if (!stack || stack->size == 0)
    {
        printf("(empty stack)\n");
        return;
    }
    while (i < stack->size)
    {
        printf("%d ", stack->numbers[i]);
        i++;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int i;

    if (argc < 2)
    {
        write(2, "error : no arguments\n", 21);
        return (1);
    }

    // Initialisation des stacks
    stack_a = create_stack(argc - 1);
    stack_b = create_stack(argc - 1);
    if (!stack_a || !stack_b)
    {
        write(2, "Error\n", 6);
        return (1);
    }

    // Remplir la pile A avec les arguments
    for (i = 1; i < argc; i++)
    {
        if (is_int(argv[i]))
        {;
            free_stack(stack_a);
            free_stack(stack_b);
            write(2, "Error\n", 6);
            return (1);
        }
        stack_a->numbers[i - 1] = ft_atoi(argv[i]);
    }
    stack_a->size = argc - 1;

    // Vérifier les doublons
    if (is_duplicated(stack_a->numbers, stack_a->size))
    {      
        free_stack(stack_a);
        free_stack(stack_b);
        write(2, "Error\n", 6);
        return (1);
    }

    // Afficher la pile initiale
    printf("Pile initiale:\n");
    print_stack(stack_a);

    // Lancer le tri
    merge_sort(stack_a, stack_b);

    // Afficher la pile triée
    printf("\nPile triée:\n");
    print_stack(stack_a);
    // Libérer la mémoire
    free_stack(stack_a);
    free_stack(stack_b);

    return (0);
}