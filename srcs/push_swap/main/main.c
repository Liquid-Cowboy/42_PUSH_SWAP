#include "push_swap.h"
/*
void    print_stack(t_stack_node *stack)
{
    ft_printf("\nStack:\t");
    while (stack)
    {
        ft_printf("%d\t", stack->value);
        stack = stack->next;
    }
}*/

int main(int ac, char **av)
{
    t_stack_node *a;
    t_stack_node *b;
    
    a = NULL;
    b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    
    a = handle_input(av);
    if (a == NULL)
        return (1);
    // now we'll sort the stack
    //print_stack(a);
    if (!stack_is_sorted(a))
        {
            if (stack_len(a) == 2)
                sa(&a, 1);
            if (stack_len(a) == 3)
                tiny_sort(&a, 1);
            else
                push_swap(&a, &b, 1);
        }
    //print_stack(a);
    //stack_a contains now all the arguments turned into ints ... we can now free the double array
    clear_stack(&a);
    clear_stack(&b);
    return (0);
}