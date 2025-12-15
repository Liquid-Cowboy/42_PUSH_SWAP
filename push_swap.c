#include "push_swap.h"

void    set_position(t_stack_node *stack)
{
    int i;
    int median;
    
    median = stack_len(stack) / 2;
    i = 0;
    while (stack)
    {
        stack->current_position = i;
        if (i <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        i++;
    }
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

void    set_target_node(t_stack_node *a, t_stack_node *b)
{
    t_stack_node    *best_match;
    t_stack_node    *current;
    int smallest;

    while (b)
    {
        smallest = INT_MAX;
        best_match = a;
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
        if (b->above_median)
        {
            if(b->target_node->above_median)
                b->push_price = b->current_position + b->target_node->current_position;
            else
                b->push_price = b->current_position + (len_a - b->target_node->current_position);
        }
        else
        {
            if(b->target_node->above_median)
                b->push_price = (len_b - b->current_position) + b->target_node->current_position;
            else
                b->push_price = (len_b - b->current_position) + (len_a - b->target_node->current_position);
        }
        b = b->next;
    }
}

void    set_cheapest(t_stack_node *stack)
{
    t_stack_node    *cheaper;
    t_stack_node    *i;

    cheaper = stack;
    i = stack;
    while(i)
    {
        if (cheaper->push_price > i->push_price)
            cheaper = i;
        i = i->next;
    }
    while(stack)
    {
        if (cheaper->push_price == stack->push_price)
            stack->cheapest = true;
        else
            stack->cheapest = false;
        stack = stack->next;
    }
}

t_stack_node    *find_cheapest(t_stack_node *stack)
{
    while (!stack->cheapest)
        stack = stack->next;
    return (stack);
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

 void   init_nodes(t_stack_node *a, t_stack_node *b)
 {
    set_position(a);
    set_position(b);
    set_target_node(a, b);
    set_price(a, b);
    set_cheapest(b);
 }

 void   assign_index(t_stack_node *stack)
 {
    int lowest;
    int i;
    t_stack_node *current;

    lowest = find_smallest(stack)->value;
    while (i < stack_len(stack))
    {
        current = stack;
        while (current)
        {
            if (current->value == lowest)
            {
                current->current_position = i;
                lowest = find_next(stack, lowest);
                break ;
            }
            current = current->next;
        }
        i++;
    }
 }

void    initial_push(t_stack_node **a, t_stack_node **b, int limit, int chunk)
{
    while (stack_len(*a) > 3)
    {
        if ((*a)->current_position < limit)
            pb(a, b);
        else
        {
            ra(a);
            if (stack_len(*b) > 1 && (*b)->current_position > (limit - chunk / 2))
                rb(b);
        }
        if ((*b)->current_position == limit)
            limit += chunk;
    }
}
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