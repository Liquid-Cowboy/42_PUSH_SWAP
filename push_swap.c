#include "push_swap.h"



#include <stdio.h>
int main(int ac, char **av)
{
    int size_a;
    //int size_b;
    int *stack_a;
    //int *stack_b;
    char **ar;
    int i;
    
    i = 0;
   // size_b = 0;
    //stack_b = NULL;

    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    size_a = 1;
    // we'll split the numbers in the first argument
    ar = ft_split(av[size_a]);
    size_a++;
    // ar now contains the numbers in the first argument (1 per string) and we'll now start concatenating on index 2 the rest of the arguments
    while (av[size_a])
        ar = cat_array(ar, ft_split(av[size_a++]));
    size_a = 0;
    while (ar[size_a])
        size_a++;
    // since arrays don't have a null terminator, size_a stands for the total number of elements in the array
   // size_b = 0;
    stack_a = create_first_stack(ar, size_a);
    if (stack_a == NULL)
    {
        free_all(ar);
        return (1);
    }
    while (stack_a[i])
        ft_printf("%d\n", stack_a[i++]);
    //stack_a contains now all the arguments turned into ints ... we can now free the double array
    free_all(ar);
    return (0);
}