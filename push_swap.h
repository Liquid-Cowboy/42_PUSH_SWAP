#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;	

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
int      repeats(long nbr, int i, char **ar);
int         ft_is_digit(char *str);
void         append_node(t_stack_node **stack, int nbr);
t_stack_node *init_stack(char **ar);
t_stack_node find_last_node(t_stack_node *stack);
int stack_len(t_stack_node *stack);

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

//push
void    push(t_stack_node **a, t_stack_node **b);
void    pa(t_stack_node **a, t_stack_node **b);
void    pb(t_stack_node **a, t_stack_node **b);


#endif