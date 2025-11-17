
#include "push_swap.h"

void    swap_ints(int *stack, int size)
{
    int temp;
    if (size < 2)
        return;
    temp = stack[0];
    stack[0] = stack[1];
    stack[1] = temp;
}

int *create_stack_a(int *size_a, int *stack_a)
{
    int *new_stack_a;
    int i;
    int j;
    
    *size_a -= 1;
    i = 1;
    j = 0;
    new_stack_a = (int*)malloc (sizeof(int) * *size_a);
        if (!new_stack_a)
            return (NULL);
        while (j < *size_a)
            new_stack_a[j++] = stack_a[i++];
        free (stack_a);
    return (new_stack_a);    
}

int *create_stack_b(int *size_b, int *stack_a, int *stack_b)
{
    int *new_stack_b;
    int i;
    int j;
    int size_before;
    
    size_before = *size_b;
    *size_b += 1;
    i = 1;
    j = 0;
    new_stack_b = (int*)malloc (sizeof(int) * *size_b);
    if (!new_stack_b)
        return (NULL);
    new_stack_b[0] = stack_a[0];
    while (i < *size_b)
        new_stack_b[i++] = stack_b[j++];
    if (size_before > 0)
        free (stack_b);
    return (new_stack_b);    
}

void    push_int(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
    if (*size_a == 0)
        return;
    // to save on lines per function, we have created create_stack_b and create_stack_a that, altough similar, are necessarilly different
    *stack_b = create_stack_b(size_b, *stack_a, *stack_b);    
    *stack_a = create_stack_a(size_a, *stack_a);
}

void    rotate_stack(int *stack, int size)
{
    int i;
    int temp;

    if (size < 2)
        return ;
    temp = stack[0];
    i = 0;
    while (i < (size - 1))
    {
        stack[i] = stack[i + 1];
        i++;
    }
    stack[i] = temp;
}

void    reverse_rotate_stack(int *stack, int size)
{
    int i;
    int temp;

    if (size < 2)
        return ;
    i = size - 1;
    temp = stack[i];
    while (i > 0)
    {
        stack[i] = stack[i - 1];
        i--;
    }
    stack[i] = temp;
}