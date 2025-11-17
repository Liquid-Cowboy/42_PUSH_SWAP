#include "push_swap.h"

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

#include <stdio.h>
int main(int ac, char **av)
{
    int size_a;
    int size_b;
    int *stack_a;
    int *stack_b;
    char **ar;
    int i = 0;

    if (ac == 1)
        return (1);
    size_a = 1;
    ar = ft_split(av[size_a]);
    size_a++;
    while (av[size_a])
        ar = cat_array(ar, ft_split(av[size_a++]));
    size_a = 0;
    while (ar[size_a])
        size_a++;
    // since arrays don't have a null terminator, size_a stands for the total number of elements in the array
    size_b = 0;
    stack_a = create_first_stack(ar, size_a);

    /* printf("%d\n", stack_a[0]);
    printf("%d\n", stack_a[1]);
    swap_ints(stack_a, size_a);
    printf("ints have been swapped\n%d\n", stack_a[0]);
    printf("%d\n", stack_a[1]);*/


   /* push_int(&stack_a, &stack_b, &size_a, &size_b);
    printf("We have now pushed from A to B\nA[0]: %d\nB[0]: %d\n", stack_a[0], stack_b[0]);
    push_int(&stack_b, &stack_a, &size_b, &size_a);
    printf("And back again\nA[0]: %d\nB[0]:", stack_a[0]);
    if (size_b > 0)
     printf(" %d", stack_b[0]);*/
     
    /*
    while (i < size_a)
     {
        printf ("Stack_A[%d] = %d\n", i, stack_a[i]);
        i++;
     }
     rotate_stack(stack_a, size_a);
     printf("We rotate.\n");
     i = 0;
    while (i < size_a)
     {
        printf ("Stack_A[%d] = %d\n", i, stack_a[i]);
        i++;
     }
    printf("We reverse rotate.\n");
     
    reverse_rotate_stack(stack_a, size_a);
     i = 0;
    while (i < size_a)
     {
        printf ("Stack_A[%d] = %d\n", i, stack_a[i]);
        i++;
     }*/

    /*
    while (ar[i])
    {
        printf("%s ", ar[i]);
        i++;
    }
        */
    free_all(ar);
    return (0);
}