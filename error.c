#include "push_swap.h"

void    clear_stack(t_stack_node **stack)
{
    t_stach_node *temp;
    t_stach_node *current;

    if (!stack || !*stack)
        return;
    current = *stack;
    while(current)
    {
        temp = current->next;
        free (current);
        current = temp;
    }
    *stack = NULL;
}

void error_clear(t_stach_node **stack, char **args)
{
    write (2, "Error\n", 6);
    clear_stack(stack);
    free_all(args);
    exit (1);
}

int repeats(long nbr, int i, char **ar)
{
    int j = 0;

    while (j < i)
    {
        if (ft_atol(ar[j]) == nbr)
            return (1);
        j++;
    }
    return (0);
}

int ft_is_digit(char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    if (*str >= '0' && *str <= '9')
        return (1);
    else
        return (0);
}