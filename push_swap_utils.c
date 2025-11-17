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

int ft_atoi(char *str)
{
    int i = 0;
    int nbr = 0;
    int is_negative = 0;

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

int *create_first_stack(char **ar, int i)
{
    int *stack;
    int j = 0;

    stack = (int*) malloc (sizeof(int) * i);
    if (!stack)
        return (NULL);
    while (j < i)
    {
        stack[j] = ft_atoi(ar[j]);
        j++;
    }
    return (stack);
}