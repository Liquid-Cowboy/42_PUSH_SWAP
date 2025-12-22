#include "push_swap.h"

//All functions required to properly initiate the stacks, so we can push from one to the other later on

void   init_nodes(t_stack_node *a, t_stack_node *b)
 {
    set_position(a);
    set_position(b);
    set_target_node(a, b);
    set_price(a, b);
    set_cheapest(b);
 }

 void    set_position(t_stack_node *stack)
{
    int i;
    int median;
    
    median = stack_len(stack) / 2;
    i = 0;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = 1;
        else
            stack->above_median = 0;
        stack = stack->next;
        i++;
    }
}


void    set_target_node(t_stack_node *a, t_stack_node *b)
{
    t_stack_node    *best_match;
    t_stack_node    *current;
    int smallest;

    while (b)
    {
        smallest = INT_MAX;
        best_match = NULL;
        current = a;
        while (current)
        {
            if ((current->value > b->value) && (current->value < smallest))
            {
                best_match = current;
                smallest = current->value;
            }
            current = current->next;
        }
        if (smallest == INT_MAX) //if the given node is higher than any node in a, it will be put before the smallest (we can then rotate the stack until it is set at the bottom)
            b->target_node = find_smallest(a);
        else
            b->target_node = best_match;
        b = b->next;
    }
}

void    set_price(t_stack_node *a, t_stack_node *b)
{
    int len_a;
    int len_b;

    len_a = stack_len(a);
    len_b = stack_len(b);
    while (b)
    {
        b->push_price = b->index;
        if (!b->above_median)
            b->push_price = len_b - b->index;
        if (b->target_node->above_median)
            b->push_price += b->target_node->index;
        else
            b->push_price += len_a - b->target_node->index;
        b = b->next;
    }
}

void    set_cheapest(t_stack_node *stack)
{
    t_stack_node    *cheaper;
    t_stack_node    *current;

    cheaper = stack;
    current = stack;
    while(current)
    {
        if (cheaper->push_price > current->push_price)
            cheaper = current;
        current = current->next;
    }
    while(stack)
    {
        if(cheaper->push_price == stack->push_price)
            stack->cheapest = 1;
        else
            stack->cheapest = 0;
        stack = stack->next;
    }
}