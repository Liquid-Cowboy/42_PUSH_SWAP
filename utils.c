#include "push_swap.h"

char   **cat_array(char **ar, char **src)
{
    int i = 0;
    int j = 0;
    char **dest;

    while (ar[i])
        i++;
    while (src[j])
        j++;
    dest = (char**) malloc (sizeof(char*) * (i + j + 1));
    if (!dest)
    {
        free_all(src);
        free_all(ar);
        return (NULL);
    }
    i = 0;
    while (ar[i])
    {
        dest[i] = create_str(dest, ar[i]);
        i++;
    }
    j = 0;
    while (src[j])
        dest[i++] = create_str(dest, src[j++]);
    dest[i] = NULL;
    free_all(src);
    free_all(ar);
    return (dest);
}

long long ft_atol(char *str)
{
    int     i = 0;
    long long    nbr = 0;
    int     is_negative = 0;

    if (str[i] == '+')
        i++;
    if (str[i] == '-')
    {
        is_negative = 1;
        i++;
    }
    while (str[i])
        nbr = nbr * 10 + (str[i++] - '0');
    if (is_negative)
        nbr = -nbr;
    return (nbr);
}

void append_node(t_stack_node **stack, int nbr)
{
    t_stack_node *node;
    t_stack_node *last_node;

    if (!stack)
        return ;
    node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!node)
        return ;
    node->value = nbr;
    node->next = NULL;
    if (!*stack)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
}

t_stack_node *init_stack(char **ar)
{
    int i;
    long long nbr;
    t_stack_node *new;

    i = 0;
    new = NULL;
    while(ar[i])
    {
        if (!ft_is_digit(ar[i]))
            error_clear(&new, ar);
        nbr = ft_atol(ar[i]);
        if (nbr > INT_MAX || nbr < INT_MIN || repeats(nbr, i, ar))
            error_clear(&new, ar);
        append_node(&new, (int)nbr);
        i++;
    }
    return (new);
}

t_stack_node *find_last_node(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while(stack->next != NULL)
        stack = stack->next;
    return(stack);
}

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

t_stack_node *find_highest(t_stack_node *stack)
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

void tiny_sort(t_stack_node **stack)
{
    if (stack_len(*stack) != 3)
        return ;
    if (*stack == find_highest(*stack))
        ra(stack);
    else if ((*stack)->next == find_highest(*stack))
        rra(stack);
    if((*stack)->value > (*stack)->next->value)
        sa(stack);
}