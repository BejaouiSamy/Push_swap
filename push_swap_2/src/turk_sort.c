#include "push_swap.h"

// Fonction pour trouver les limites des chunks
void find_chunks_limits(t_stack *a, int *chunks, int nb_chunks)
{
    int min;
    int max;
    int i;
    int range;

    min = a->numbers[0];
    max = a->numbers[0];
    i = 1;
    // Trouve min et max
    while (i < a->size)
    {
        if (a->numbers[i] < min)
            min = a->numbers[i];
        if (a->numbers[i] > max)
            max = a->numbers[i];
        i++;
    }
    range = max - min + 1;
    i = 0;
    // Calcule les limites des chunks
    while (i < nb_chunks)
    {
        chunks[i] = min + (range * (i + 1)) / nb_chunks;
        i++;
    }
}

// Effectue les rotations necessaires pour amener un nombre
// en haut de la pile
void bring_to_top(t_stack *stack, int pos)
{
    int size;
    int rotations;

    size = stack->size;
    if (pos == 0)
        return;
    if (pos <= size / 2)
    {
        rotations = pos;
        while (rotations--)
            ra(stack);
    }
    else
    {
        rotations = size - pos;
        while (rotations--)
            rra(stack);
    }
}

// Trouve le meilleur nombre a pousser dans le chunk actuel
int find_best_push(t_stack *a, int chunk_min, int chunk_max)
{
    int i;
    int best_pos;

    i = 0;
    best_pos = -1;
    while (i < a->size)
    {
        if (a->numbers[i] >= chunk_min && a->numbers[i] <= chunk_max)
        {
            if (best_pos == -1 || i < best_pos)
                best_pos = i;
        }
        i++;
    }
    return (best_pos);
}

// Nouvelle fonction principale de tri (Turk)
void turk_sort(t_stack *a, t_stack *b)
{
    int chunks[NB_CHUNKS];
    int i;
    int chunk_min;
    int chunk_max;
    int count;
    int best_pos;
    int target_pos;
    int max_pos;
    
    i = 0;
    int chunk_size[] = {10, 15, 15, 15, 15, 15, 15};
    find_chunks_limits(a, chunks, NB_CHUNKS);
    // Push vers B de maniere optimisee
    while(i < NB_CHUNKS)
    {
        chunk_min = (i == 0) ? INT_MIN : chunks[i - 1];
        chunk_max = chunks[i];
        count = 0;
        while (count < chunk_size[i] && a->size > 0)
        {
            best_pos = find_best_push(a, chunk_min, chunk_max);
            if (best_pos == -1)
                break;
                // Si le nombre est dans la premiere moitie de B
                // On peut faire une rotation double
            if (b->size > 0)
            {
                target_pos = find_target_position(b, a->numbers[best_pos]);
                if (best_pos <= a->size / 2 && target_pos <= b->size / 2)
                {
                    smart_rotate(a, b, best_pos, target_pos);
                }
            }
            else
                bring_to_top(a, best_pos);
            pb(a, b);
            count++;
        }
        i++;
    }
    // Retour optimisee vers A
    while (b->size > 0)
    {
        max_pos = find_max(b);
        bring_to_top(b, max_pos);
        pa(a, b);
    }
}

// Fonction pour trouver le max
int find_max(t_stack *stack)
{
    int max_pos;
    int i;

    i = 1;
    max_pos = 0;
    while (i < stack->size)
    {
        if (stack->numbers[i] > stack->numbers[max_pos])
            max_pos = i;
        i++;
    }
    return (max_pos);
}