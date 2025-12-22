#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include "ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int			value;
	int			index;
	int			push_price;
	bool			above_median;
	bool			cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;	

//Functions used in the conversion of arguments (as strings) to nodes in a linked list.

char   **cat_array(char **ar, char **src);
long long ft_atol(char *str);
void append_node(t_stack_node **stack, int nbr);
t_stack_node *init_stack(char **ar);

//Error treatment and freeing allocated memmory.

void    clear_stack(t_stack_node **stack);
void error_clear(t_stack_node **stack, char **args);
int repeats(long nbr, int i, char **ar);
int ft_is_digit(char *str);

//A regular split.

int count_wd(char *str);
char    *create_str(char **ar, char *str);
void    free_all(char **ar);
char **ft_split(char *str);

//ops

void    push(t_stack_node **a, t_stack_node **b);
void    pa(t_stack_node **a, t_stack_node **b);
void    pb(t_stack_node **a, t_stack_node **b);

void    swap(t_stack_node **head);
void sa(t_stack_node **a);
void sb(t_stack_node **b);
void ss(t_stack_node **a, t_stack_node**b);

void    rotate(t_stack_node **head);
void    ra(t_stack_node **a);
void    rb(t_stack_node **b);
void    rr(t_stack_node **a, t_stack_node **b);

void    reverse_rotate(t_stack_node **head);
void    rra(t_stack_node **a);
void    rrb(t_stack_node **b);
void    rrr(t_stack_node **a, t_stack_node **b);



#include "push_swap.h"

//Small utility functions used throughout the sorting phase.

int stack_len(t_stack_node *stack);
int stack_is_sorted(t_stack_node *stack);
t_stack_node *find_biggest(t_stack_node *stack);
t_stack_node    *find_smallest(t_stack_node *stack);
t_stack_node *find_last_node(t_stack_node *stack);
t_stack_node    *find_cheapest(t_stack_node *stack);



//All functions required to properly initiate the stacks, so we can push from one to the other later on

void   init_nodes(t_stack_node *a, t_stack_node *b);
void    set_position(t_stack_node *stack);
void    set_target_node(t_stack_node *a, t_stack_node *b);
void    set_price(t_stack_node *a, t_stack_node *b);
void    set_cheapest(t_stack_node *stack);

//Main sorting phase.

void    push_swap(t_stack_node **a, t_stack_node **b);
void   assign_index(t_stack_node *stack);
int    find_next(t_stack_node *stack, int prev);
void    initial_push(t_stack_node **a, t_stack_node **b, int limit, int chunk);
void tiny_sort(t_stack_node **stack);
void    move_nodes(t_stack_node **a, t_stack_node **b);
void    rotate_loop(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void    reverse_rotate_loop(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void    set_order(t_stack_node **stack, t_stack_node *top_node, char c);


#endif
