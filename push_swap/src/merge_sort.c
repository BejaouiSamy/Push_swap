#include "push_swap.h"


// Trouve le plus petit element de la pile
int find_min(t_stack *stack, int start, int size)
{
    int min;
    int min_pos;
    int i;

    if (!stack || start >= stack->size)
        return (-1);
    min = stack->numbers[start];
    min_pos = start;
    i = start + 1;
    while (i < size && i < stack->size)
    {
        if (stack->numbers[i] < min)
        {
            min = stack->numbers[i];
            min_pos = i;
        }
        i++;
    }
    return (min_pos);
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
    if (!a || pos < 0 || pos >= a->size)
        return;
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
    int min_pos;

    chunk_size = 20; // Taille a ajuster pour les tests
    while (a->size > 0)
    {
        // Verifie que le chunk ne depasse pas la taille de la pile
        int current_chunk = (chunk_size < a->size) ? chunk_size : a->size;
        // Trouve le minimum pour le chunk actuel
        min_pos = find_min(a, 0, current_chunk);
        // Amene le minimum au sommet de A
        // Push le minimum vers B;
        if (min_pos >= 0 && min_pos < a->size)
        {
            bring_to_top(a, min_pos);
            pb(a, b);
        }
        // Ne cherche que dans les limites de la taille actuelle
    }
    // Retourne tous les elements de B vers A (ordre croissant)
    while (b->size > 0)
        pa(a, b);
}