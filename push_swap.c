#include "push_swap.h"

void    set_position(t_stack_node *stack)
{
    int i;

    i = 0;
    if (!stack)
        return ;
    while (stack)
    {
        stack->current_position = i;
        if (i <= (stack_len(stack) / 2))
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
    while (b)
    {
        if (b->above_median)
        {
            if(b->target_node->above_median)
                b->push_price = b->current_position + b->target_node->current_position;
            else
                b->push_price = b->current_position + (stack_len(a) - b->target_node->current_position);
        }
        else
        {
            if(b->target_node->above_median)
                b->push_price = (stack_len(b) - b->current_position) + b->target_node->current_position;
            else
                b->push_price = (stack_len(b) - b->current_position) + (stack_len(a) - b->target_node->current_position);
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

void    sort_al(t_stack_node **a, t_stack_node **b)
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
 int   check_sorted(int *sorted_stack, int len)
 {
    int i;

    i = 0;
    while ((i + 1) < len)
    {
        if (sorted_stack[i] > sorted_stack[i + 1])
            return (0);
        i++;
    }
    return (1);
 }

 void   quick_sort(int *sorted_stack, int len)
 {
    int i;
    int temp;

    i = 0;
    while(!check_sorted(sorted_stack, len))
    {
        i = 0;
        while((i + 1) < len)
        {
            if (sorted_stack[i] > sorted_stack[i + 1])
            {
                temp = sorted_stack[i];
                sorted_stack[i] = sorted_stack[i + 1];
                sorted_stack[i + 1] = temp;
            }
            i++;
        }
    }
 }

int median_value(t_stack_node *a)
{
    int *sorted_stack;
    int i;
    int value;
    int len;

    i = 0;
    len = stack_len(a);
    sorted_stack = malloc(len * (sizeof(int)));
    if (!sorted_stack)
        return (0);
    while(i < len)
    {
        sorted_stack[i++] = a->value;
        a = a->next;
    }
    quick_sort(sorted_stack, len);
    value = sorted_stack[len / 2];
    free (sorted_stack);
    return(value);
}


void    push_swap(t_stack_node **a, t_stack_node **b)
{
    int median;

    if (!a || !*a)
        return ;
    median = median_value(*a);
    if (median == 0)
        return ;
    while (stack_len(*a) > 3)
    {
        pb(a, b);
        if ((stack_len(*b) > 1) && ((*b)->value > median))
        rb(b);
    }
    tiny_sort(a);
    while (*b)
    {
        init_nodes(*a, *b);
        sort_al(a, b);
    }
    set_position(*a);
    set_order(a, find_smallest(*a), 'a');
}