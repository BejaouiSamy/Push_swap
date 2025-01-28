#include "push_swap.h"


// Trouve le plus petit element de la pile
int find_min(t_stack *stack, int start, int size)
{
    int min;
    int i;

    min = INT_MAX;
    i = start;
    while (i < size)
    {
        if (stack->numbers[i] < min)
            min = stack->numbers[i];
        i++;
    }
    return (min);
}

// Trouve la position du nombre dans la pile
int find_position(t_stack *stack, int num)
{
    int i;

    i = 0;
    while (i < stack->size)
    {
        if (stack->numbers[i] == num)
            return (i);
        i++;
    }
    return (-1);
}

// Effectue les rotations necessaires pour amener un nombre
// en haut de la pile
void bring_to_top(t_stack *a, int pos)
{
    if (pos <= a->size / 2)
    {
        // Rotation vers le haut si la position est dans la 1ere moitier
        while (pos > 0)
        {
            ra(a);
            pos--;
        }
    }
    else
    {
        while (pos < a->size)
        {
            rra(a);
            pos++;
        }
    }
}

// Fonction principale de tri merge
void merge_sort(t_stack *a, t_stack *b)
{
    int chunk_size;
    int i;
    int min;

    chunk_size = 20; // Taille a ajuster pour les tests
    while (a->size > 0)
    {
        // Trouve le minimum pour le chunk actuel
        min = find_min(a, 0, chunk_size < a->size ? chunk_size : a->size);
        //Trouve la position du minimum
        int pos;

        pos = find_position(a, min);
        // Amene le minimum au sommet de A
        bring_to_top(a, pos);
        // Push le minimum vers B;
        pb (a, b);
    }
    // Retourne tous les elements de B vers A (ordre croissant)
    while (b->size > 0)
        pa(a, b);
}