#include "push_swap.h"

//Functions used in the conversion of arguments (as strings) to nodes in a linked list.

t_stack_node    *handle_input(char **arg)
{
    int i;
    char    **ar;
    t_stack_node *stack;

    i = 1;
    // we'll split the numbers in the first argument
    ar = ft_split(arg[i]);
    // ar now contains the numbers in the first argument (1 per string) and we'll now start concatenating on index 2 the rest of the arguments
    i++;
    while (arg[i])
        ar = cat_array(ar, ft_split(arg[i++]));
    stack = init_stack(ar);
    if (ar)
        free_all(ar);
    return (stack);
}


char   **cat_array(char **ar, char **src) //concatenates multiple inputs into a string array
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

long long ft_atol(char *str) //long long data type ensures inputs that go over the long_max
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

void append_node(t_stack_node **stack, int nbr) //creates a new node with the value atribute
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
            error_clear(&new, ar); //error clear frees both the string array and the malloc-ed stack
        nbr = ft_atol(ar[i]);
        if (nbr > INT_MAX || nbr < INT_MIN || repeats(nbr, i, ar))
            error_clear(&new, ar);
        append_node(&new, (int)nbr);
        i++;
    }
    return (new);
}