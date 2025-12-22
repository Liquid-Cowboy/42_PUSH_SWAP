#include "push_swap.h"

//This file here pertains to the main sorting phase.

void    push_swap(t_stack_node **a, t_stack_node **b)
{
    int chunk;
    int limit;

    if (!a || !*a)
        return ;
    assign_index(*a);
    if (stack_len(*a) <= 100)
        chunk = 15;
    if (stack_len(*a) <= 500)
        chunk = 25;
    limit = chunk;
    initial_push(a, b, limit, chunk);
    tiny_sort(a);
    while (*b)
    {
        init_nodes(*a, *b);
        move_nodes(a, b);
    }
    set_position(*a);
    set_order(a, find_smallest(*a), 'a');
}

 void   assign_index(t_stack_node *stack)
 {
    int lowest;
    int i;
    t_stack_node *current;

    lowest = find_smallest(stack)->value;
    i = 0;
    while (i < stack_len(stack))
    {
        current = stack;
        while (current)
        {
            if (current->value == lowest)
            {
                current->index = i;
                lowest = find_next(stack, lowest);
                break ;
            }
            current = current->next;
        }
        i++;
    }
 }

 int    find_next(t_stack_node *stack, int prev)
{
    int next;

    next = INT_MAX;
    while(stack)
    {
        if (prev < stack->value && stack->value < next)
        {
            next = stack->value;
        }
        stack = stack->next;
    }
    return (next);
}

 void    initial_push(t_stack_node **a, t_stack_node **b, int limit, int chunk)
{
    while (stack_len(*a) > 3)
    {
        if ((*a)->index < limit)
        {
            pb(a, b);
            if (*b && (*b)->index == (limit - 1))
                limit += chunk;
            if (stack_len(*b) > 1 && (*b)->index > (limit - chunk / 2))
                rb(b);
        }
        else
            ra(a);
    }
}

void tiny_sort(t_stack_node **stack)
{
    if (stack_len(*stack) != 3)
        return ;
    if (*stack == find_biggest(*stack))
        ra(stack);
    else if ((*stack)->next == find_biggest(*stack))
        rra(stack);
    if((*stack)->value > (*stack)->next->value)
        sa(stack);
}

void    move_nodes(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest;

    cheapest = find_cheapest(*b);
    if (cheapest->above_median && cheapest->target_node->above_median)
        rotate_loop(a, b, cheapest);
    else if (!cheapest->above_median && !cheapest->target_node->above_median)
        reverse_rotate_loop(a, b, cheapest);
    set_order(a, cheapest->target_node, 'a');
    set_order(b, cheapest, 'b');
    pa(a, b);            
}

void    rotate_loop(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
    while ((cheapest->target_node != *a) && (cheapest != *b))
        rr(a, b);
    set_position(*a);
    set_position(*b);
}

void    reverse_rotate_loop(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
    while ((cheapest->target_node != *a) && (cheapest != *b))
        rrr(a, b);
    set_position(*a);
    set_position(*b);
}

void    set_order(t_stack_node **stack, t_stack_node *top_node, char c)
{
    while (top_node != *stack)
    {
        if (top_node->above_median)
            {
                if (c == 'a')
                    ra(stack);
                else
                    rb(stack);
            }
        else
            {
                if (c == 'a')
                    rra(stack);
                else
                    rrb(stack);
            }
    }
}