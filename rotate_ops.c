void    rotate(t_stack_node **head)
{
    t_stack_node *last;

    if (!head || !*head || stack_len(*head) <= 1)
        return;   
    *head = (*head)->next
    last = find_last_node(*head);
    last->next = (*head)->prev;
    (*head)->prev->prev = last;
    (*head)->prev->next = NULL;
    (*head)->prev = NULL;
}

void    ra(t_stack_node **a)
{
    rotate(a);
    ft_printf("ra\n");
}

void    rb(t_stack_node **b)
{
    rotate(b);
    ft_printf("rb\n");
}

void    rr(t_stack_node **a, t_stack_node **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}