#include "push_swap.h"

//Fonction pour trouver la position ideale dans B
int find_target_position(t_stack *b, int num)
{
    int i;
    int best_pos;

    i = 0;
    best_pos = 0;
    while (i < b->size)
    {
        if (b->numbers[i] < num && b->numbers[best_pos] < b->numbers[i])
            best_pos = i;
        i++;
    }
    return (best_pos);
}