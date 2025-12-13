#include "../push_swap.h"

void    reverse_rotate(t_stack_node **head)
{
    t_stack_node *last;
    
    if (!head || !*head || stack_len(*head) <= 1)
        return;
    last = find_last_node(*head);
    (*head)->prev = last;
    last->next = *head;
    last->prev->next = NULL;
    last->prev = NULL;
    *head = last;
}

void    rra(t_stack_node **a)
{
    
    reverse_rotate(a);
    ft_printf("rra\n");
}

void    rrb(t_stack_node **b)
{
    reverse_rotate(b);
    ft_printf("rrb\n");
}

void    rrr(t_stack_node **a, t_stack_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_printf("rrr\n");
}