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
	int			current_position;
	int			final_index;
	int			push_price;
	bool			above_median;
	bool			cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;	

// split in case numbers are passed as strings divided by spaces
void	free_all(char **ar);
int	count_wd(char *str);
char	*create_str(char **ar, char *str);
char	**ft_split(char *str);

// utils - tools to help receive the arguments and initiate the first stack
void tiny_sort(t_stack_node **stack);
void         append_node(t_stack_node **stack, int nbr);
int	stack_is_sorted(t_stack_node *stack);
int     ft_is_digit(char *str);
int stack_len(t_stack_node *stack);
long long    ft_atol(char *str);
char   **cat_array(char **ar, char **src);
t_stack_node *init_stack(char **ar);
t_stack_node *find_last_node(t_stack_node *stack);

//error
void    clear_stack(t_stack_node **stack);
void 	error_clear(t_stack_node **stack, char **args);
int		repeats(long nbr, int i, char **ar);
int		ft_is_digit(char *str);

//swap
void    swap(t_stack_node **head);
void    sa(t_stack_node **a);
void    sb(t_stack_node **b);
void    ss(t_stack_node **a, t_stack_node **b);

//rotate
void    rotate(t_stack_node **head);
void    ra(t_stack_node **a);
void    rb(t_stack_node **b);
void    rr(t_stack_node **a, t_stack_node **b);

//reverse rotate
void    reverse_rotate(t_stack_node **head);
void    rra(t_stack_node **a);
void    rrb(t_stack_node **b);
void    rrr(t_stack_node **a, t_stack_node **b);

//push
void    push(t_stack_node **a, t_stack_node **b);
void    pa(t_stack_node **a, t_stack_node **b);
void    pb(t_stack_node **a, t_stack_node **b);

//push_swap
void    set_position(t_stack_node *stack);
void    set_target_node(t_stack_node *a, t_stack_node *b);
void    set_price(t_stack_node *a, t_stack_node *b);
void    set_cheapest(t_stack_node *stack);
void    rotate_loop(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void    reverse_rotate_loop(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void    set_order(t_stack_node **stack, t_stack_node *top_node, char c);
void    sort_al(t_stack_node **a, t_stack_node **b);
void   init_nodes(t_stack_node *a, t_stack_node *b);
void    push_swap(t_stack_node **a, t_stack_node **b);
t_stack_node    *find_smallest(t_stack_node *stack);
t_stack_node    *find_cheapest(t_stack_node *stack);

#endif
