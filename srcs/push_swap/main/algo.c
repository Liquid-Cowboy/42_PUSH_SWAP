#include "push_swap.h"

//This file here pertains to the main sorting phase.

void    push_swap(t_stack_node **a, t_stack_node **b, int print)
{
    int average;

    if (!a || !*a)
        return ;
    while (stack_len(*a) > 3 && !stack_is_sorted(*a))
    {
        pb(a, b, print);
        average = get_average(*a);
        if ((stack_len(*b) > 1) && ((*b)->value < average))
            rb(b, print);
    }
    tiny_sort(a, print);
    while (*b)
    {
        init_nodes(*a, *b);
        move_nodes(a, b, print);
    }
    init_nodes(*a, *b);
    set_order(a, find_smallest(*a), 'a', print);
}

int get_average(t_stack_node *stack)
{
    int sum;
    t_stack_node *current;

    current = stack;
    sum = 0;
    while (current)
    {
        sum += current->value;
        current = current->next;
    }
    return (sum / stack_len(stack));
}
 
void tiny_sort(t_stack_node **stack, int print)
{
    if (stack_len(*stack) != 3)
        return ;
    if (*stack == find_biggest(*stack))
        ra(stack, print);
    else if ((*stack)->next == find_biggest(*stack))
        rra(stack, print);
    if((*stack)->value > (*stack)->next->value)
        sa(stack, print);
}

void    move_nodes(t_stack_node **a, t_stack_node **b, int print)
{
    t_stack_node *cheapest;

    cheapest = find_cheapest(*b);
    if (cheapest->above_median && cheapest->target_node->above_median)
        while (*b != cheapest && *a != cheapest->target_node)
            rr(a, b, print);
    else if (!cheapest->above_median && !cheapest->target_node->above_median)
        while (*b != cheapest && *a != cheapest->target_node)
            rrr(a, b, print);
    init_nodes(*a, *b);
    set_order(b, cheapest, 'b', print);
    set_order(a, cheapest->target_node, 'a', print);
    pa(a, b, print);            
}

void    set_order(t_stack_node **stack, t_stack_node *top_node, char c, int print)
{
    while (top_node != *stack)
    {
        if (top_node->above_median)
            {
                if (c == 'a')
                    ra(stack, print);
                else
                    rb(stack, print);
            }
        else
            {
                if (c == 'a')
                    rra(stack, print);
                else
                    rrb(stack, print);
            }
    }
}