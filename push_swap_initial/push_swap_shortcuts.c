#include "push_swap.h"

void sa(int *stack_a, size_a)
{
    write (1, "sa\n", 3);
    swap_ints(stack_a, size_a);
}

void sb(int *stack_b, size_b)
{
    write (1, "sb\n", 3);
    swap_ints(stack_b, size_b);
}

void ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
    write (1, "ss\n", 3);
    swap_ints(stack_a, size_a);
    swap_ints(stack_b, size_b);
}

void pa(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
    write (1, "pa\n", 3);
    push_int(stack_b, stack_a, *size_b, *size_a);
}

void pb(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
    write (1, "pb\n", 3);
    push_int(stack_a, stack_b, *size_a, *size_b);
}

void ra(int *stack_a, int size_a)
{
    write (1, "ra\n", 3);
    rotate_stack(stack_a, size_a);
}

void rb(int *stack_b, int size_b)
{
    write (1, "rb\n", 3);
    rotate_stack(stack_b, size_b);
}

void rr(int *stack_a, int *stack_b, int size_a, int size_b)
{
    write (1, "rr\n", 3);
    rotate_stack(stack_a, size_a);
    rotate_stack(stack_b, size_b);
}
void rra(int *stack_a, int size_a)
{
    write (1, "rra\n", 4);
    reverse_rotate_stack(stack_a, size_a);
}

void rrb(int *stack_b, int size_b)
{
    write (1, "rrb\n", 4);
    reverse_rotate_stack(stack_b, size_b);
}

void rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
    write (1, "rrr\n", 4);
    reverse_rotate_stack(stack_a, size_a);
    reverse_rotate_stack(stack_b, size_b);
}