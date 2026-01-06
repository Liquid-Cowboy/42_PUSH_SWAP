/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_conversion_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:35:21 by mnogueir          #+#    #+#             */
/*   Updated: 2026/01/06 11:43:07 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->value = nbr;
	node->next = NULL;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack_node	*init_stack(char **ar)
{
	int				i;
	long long		nbr;
	t_stack_node	*new;

	i = 0;
	new = NULL;
	while (ar[i])
	{
		if (!ft_is_digit(ar[i]))
			error_clear(&new, ar);
		nbr = ft_atol(ar[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || repeats(nbr, i, ar))
			error_clear(&new, ar);
		append_node(&new, (int)nbr);
		i++;
	}
	return (new);
}
