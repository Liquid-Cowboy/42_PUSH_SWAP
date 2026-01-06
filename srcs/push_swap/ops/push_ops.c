/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:36:08 by mnogueir          #+#    #+#             */
/*   Updated: 2026/01/06 12:09:35 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*to_push;

	if (!a || !*a)
		return ;
	to_push = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	if (*b)
		(*b)->prev = to_push;
	to_push->next = *b;
	*b = to_push;
}

void	pa(t_stack_node **a, t_stack_node **b, int print)
{
	push(b, a);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, int print)
{
	push(a, b);
	if (print)
		ft_printf("pb\n");
}
