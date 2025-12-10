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

long ft_atol(char *str)
{
    int     i = 0;
    long    nbr = 0;
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

int repeats(int nbr, int i, char **ar)
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

int *create_first_stack(char **ar, int size)
{
    int *stack;
    int i;
    long nbr;
    i = 0;
    stack = (int*) malloc (sizeof(int) * size);
    if (!stack)
        return (NULL);
    while (i < size)
    {
        if (!(ft_is_digit(ar[i])))
        {
            free (stack);
            write(1, "error", 5);
            return (NULL);
        }        
        nbr = ft_atol(ar[i]);
        if (nbr > INT_MAX || nbr < INT_MIN || repeats(nbr, i, ar))
        {
            free (stack);
            write(1, "error", 5);
            return (NULL);
        }
        stack[i] = (int)nbr;
        i++;
    }
    return (stack);
}

int stack_is_sorted(int *stack, int size)
{
    int i;

    i = 0;
    while ((i + 1) < size)
    {
        if (stack[i] > stack[i + 1])
            return (0)
        i++;
    }
    return (1);
}

int find_highest(int *stack, int size)
{
    int i;
    int highest_index 
    
    highest_index = 0;
    i = 0;
    while ((i + 1) < size)
    {
        if(stack[i + 1] > stack[i])
            highest_index = stack[i + 1];
        i++;
    }
    return (highest_index);
}

void    tiny_sort(int *stack, int size)
{
    highest_index = find_highest(stack, size);
    if (highest_index == 0)
        ra(stack, size);
    elif (highest_index == 1)
        rra(stack, size);
    if (stack[0] > stack[1])
        sa(stack, size);
}

int     above_median(int *stack, int size, int nbr)
{
    int i;

    i = 0;
    while (stack[i] != nbr)
        i++;
    if (i > (size / 2))
        return (1);
    else
        return (0);
}

int     set_cost(int *stack, int size, int nbr)
{
    int i;
    
    i = 0;
    while (stack[i] != nbr)
        i++;
    if (above_median(stack, size, nbr))
        return (size - i);
    else
        return (i);
}

int     find_target(int *stack, int size, int nbr)
{
    int i;

    i = 0;
    target = 0;
    while(stack[i] < nbr && i < size)
        i++;
    target = stack[i];
    while(i < size)
    {
        if (stack[i] < target && stack[i] > nbr)
            target = stack[i];
        i++;
    }
    return (target);
}



void    push_swap(int *stack_a, int *stack_b, int size_a, int size_b)
{
    int i;
    int pair_cost;

    i = 0;
    pair_cost = 0;
    while (size_a > 3)
        pb(stack_a, stack_b, size_a, size_b);
    tiny_sort(stack_a, size_a);
    while (stack_b[i])
    {
        if 
        pair_cost = (set_cost(stack_b, size_b, stack_b[i]) + set_cost(stack_a, size_a, find_target(stack_a, size_a, stack_b[i])));


    }

}