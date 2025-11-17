#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>

// split

int count_wd(char *str);
char    *create_str(char **ar, char *str);
void    free_all(char **ar);
char **ft_split(char *str);

// utils

int ft_atoi(char *str);
char   **cat_array(char **ar, char **src);
int *create_first_stack(char **ar, int i); //creates first stack_a

// ops
void    swap_ints(int *stack, int i);

int *create_stack_a(int *size_a, int *stack_a);
int *create_stack_b(int *size_b, int *stack_a, int *stack_b);
void    push_int(int **stack_a, int **stack_b, int *size_a, int *size_b);

void    rotate_stack(int *stack, int size);
void    reverse_rotate_stack(int *stack, int size);

// main








#endif