#include "push_swap.h"

//This file contains small utility functions used throughout the sorting phase.

int stack_len(t_stack_node *stack)
{
    int i;

    if (!stack)
        return (0);
    i = 1;
    while (stack->next)
    {
        stack = stack->next;
        i++;
    }
    return (i);
}

int stack_is_sorted(t_stack_node *stack)
{
    while(stack->next)
    {
        if (!stack)
            return (1);
        if(stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

t_stack_node *find_biggest(t_stack_node *stack)
{
    t_stack_node *to_deliver;

    if (!stack)
        return (NULL);
    to_deliver = stack;
    while (stack->next)
    {
        if (to_deliver->value < stack->value)
            to_deliver = stack;
        stack = stack->next;
    }
    return (to_deliver);
}

t_stack_node    *find_smallest(t_stack_node *stack)
{
    int i;
    t_stack_node *to_deliver;

    if (!stack)
        return (NULL);
    i = INT_MAX;
    while(stack)
    {
        if (i > stack->value)
        {
            i = stack->value;
            to_deliver = stack;
        }
        stack = stack->next;
    }
    return (to_deliver);
}

t_stack_node *find_last_node(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while(stack->next != NULL)
        stack = stack->next;
    return(stack);
}

t_stack_node    *find_cheapest(t_stack_node *stack)
{
    while (!stack->cheapest)
        stack = stack->next;
    return (stack);
}
