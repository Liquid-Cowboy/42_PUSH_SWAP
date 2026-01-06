/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:34:02 by mnogueir          #+#    #+#             */
/*   Updated: 2026/01/06 10:57:33 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "srcs/ft_printf/ft_printf.h"
# include "srcs/bonus/get_next_line.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_price;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;	

//Functions used in the conversion of arguments 
//(as strings) to nodes in a linked list.

t_stack_node	*handle_input(char **arg);
void			cat_string(char **ar, char **dest, char **src);
char			**cat_array(char **ar, char **src);
long long		ft_atol(char *str);
void			append_node(t_stack_node **stack, int nbr);
t_stack_node	*init_stack(char **ar);

//Error treatment and freeing allocated memmory.

void			clear_stack(t_stack_node **stack);
void			error_clear(t_stack_node **stack, char **args);
int				repeats(long nbr, int i, char **ar);
int				ft_is_digit(char *str);

//A regular split.

int				count_wd(char *str);
char			*create_str(char **ar, char *str);
void			free_all(char **ar);
char			**ft_split(char *str);

//ops

void			push(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b, int print);
void			pb(t_stack_node **a, t_stack_node **b, int print);

void			swap(t_stack_node **head);
void			sa(t_stack_node **a, int print);
void			sb(t_stack_node **b, int print);
void			ss(t_stack_node **a, t_stack_node**b, int print);

void			rotate(t_stack_node **head);
void			ra(t_stack_node **a, int print);
void			rb(t_stack_node **b, int print);
void			rr(t_stack_node **a, t_stack_node **b, int print);

void			reverse_rotate(t_stack_node **head);
void			rra(t_stack_node **a, int print);
void			rrb(t_stack_node **b, int print);
void			rrr(t_stack_node **a, t_stack_node **b, int print);

//Small utility functions used throughout the sorting phase.

int				stack_len(t_stack_node *stack);
int				stack_is_sorted(t_stack_node *stack);
t_stack_node	*find_biggest(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *stack);
t_stack_node	*find_cheapest(t_stack_node *stack);

//All functions required to properly initiate the stacks,
//so we can push from one to the other later on

void			init_nodes(t_stack_node *a, t_stack_node *b);
void			set_position(t_stack_node *stack);
void			set_target_node(t_stack_node *a, t_stack_node *b);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);

//Main sorting phase.

void			push_swap(t_stack_node **a, t_stack_node **b, int print);
int				get_average(t_stack_node *stack);
void			tiny_sort(t_stack_node **stack, int print);
void			move_nodes(t_stack_node **a, t_stack_node **b, int print);
void			set_order(t_stack_node **stack, t_stack_node *top_node,
					char c, int print);

#endif
