/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:36:04 by mnogueir          #+#    #+#             */
/*   Updated: 2026/01/06 12:41:08 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

//This file contains small utility functions used throughout the sorting phase.

t_stack_node	*find_smallest(t_stack_node *stack)
{
	int				i;
	t_stack_node	*to_deliver;

	if (!stack)
		return (NULL);
	i = INT_MAX;
	while (stack)
	{
		if (i > stack->value)
		{
			i = stack->value;
			to_deliver = stack;
		}
		stack = stack->next;
	}
	return (to_deliver);
}

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_cheapest(t_stack_node *stack)
{
	while (stack && !stack->cheapest)
		stack = stack->next;
	return (stack);
}
