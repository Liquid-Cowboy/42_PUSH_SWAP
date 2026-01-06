/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:36:13 by mnogueir          #+#    #+#             */
/*   Updated: 2026/01/06 12:13:49 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	rotate(t_stack_node **head)
{
	t_stack_node	*last;

	if (!head || !*head || stack_len(*head) <= 1)
		return ;
	*head = (*head)->next;
	last = find_last_node(*head);
	last->next = (*head)->prev;
	(*head)->prev->prev = last;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}

void	ra(t_stack_node **a, int print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, int print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}
