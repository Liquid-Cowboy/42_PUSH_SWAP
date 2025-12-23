#include "push_swap.h"

void    swap(t_stack_node **head)
{
    if (!head || !*head || stack_len(*head) <= 1)
        return ;
    *head = (*head)->next;
    (*head)->prev->prev = *head;
    (*head)->prev->next = (*head)->next;
    if ((*head)->next)
        (*head)->next->prev = (*head)->prev;
    (*head)->next = (*head)->prev;
    (*head)->prev = NULL;
    
}

void sa(t_stack_node **a, int print)
{
    swap(a);
    if (print)
        ft_printf("sa\n");
}

void sb(t_stack_node **b, int print)
{
    swap(b);
    if (print)
        ft_printf("sb\n");
}

void ss(t_stack_node **a, t_stack_node**b, int print)
{
    swap(a);
    swap(b);
    if (print)
        ft_printf("ss\n");
}