#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

// split

int     count_wd(char *str);
char    *create_str(char **ar, char *str);
void    free_all(char **ar);
char    **ft_split(char *str);

// utils

long    ft_atol(char *str);
int     repeats(int nbr, int i, char **ar);
int     ft_is_digit(char *str);
char   **cat_array(char **ar, char **src);
int    *create_first_stack(char **ar, int size); //creates first stack_a

// ops
void    swap_ints(int *stack, int i);

int     *create_stack_a(int *size_a, int *stack_a);
int     *create_stack_b(int *size_b, int *stack_a, int *stack_b);
void    push_int(int **stack_a, int **stack_b, int *size_a, int *size_b);

void    rotate_stack(int *stack, int size);
void    reverse_rotate_stack(int *stack, int size);

// shortcuts

void sa(int *stack_a, int size_a);
void sb(int *stack_b, int size_b);
void ss(int *stack_a, int *stack_b, int size_a, int size_b);
void pa(int **stack_a, int **stack_b, int *size_a, int *size_b);
void pb(int **stack_a, int **stack_b, int *size_a, int *size_b);
void ra(int *stack_a, int size_a);
void rb(int *stack_b, int size_b);
void rr(int *stack_a, int *stack_b, int size_a, int size_b);
void rra(int *stack_a, int size_a);
void rrb(int *stack_b, int size_b);
void rrr(int *stack_a, int *stack_b, int size_a, int size_b);

#endif