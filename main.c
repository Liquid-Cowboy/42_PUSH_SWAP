#include "push_swap.h"



#include <stdio.h>
int main(int ac, char **av)
{
    t_stack_node *a;
    t_stack_node *b;
   // t_stack_node *to_print;
    char **ar;
    int i;
    
    a = NULL;
    b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    i = 1;
    // we'll split the numbers in the first argument
    ar = ft_split(av[i]);
    i++;
    // ar now contains the numbers in the first argument (1 per string) and we'll now start concatenating on index 2 the rest of the arguments
    while (av[i])
        ar = cat_array(ar, ft_split(av[i++]));
    a = init_stack(ar);
    if (a == NULL)
    {
        free_all(ar);
        return (1);
    }
    // now we'll sort the stack
    if (!stack_is_sorted(a))
        {
            if (stack_len(a) == 2)
                sa(&a);
            if (stack_len(a) == 3)
                tiny_sort(&a);
            else
                push_swap(&a, &b);
        }
        /*
    to_print = a;
    while(to_print)
    {
        ft_printf("%d\t", to_print->value);
        to_print = to_print->next;
    }*/
 
    //stack_a contains now all the arguments turned into ints ... we can now free the double array
    clear_stack(&a);
    free_all(ar);
    return (0);
}