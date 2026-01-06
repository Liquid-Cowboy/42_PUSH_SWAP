/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:36:00 by mnogueir          #+#    #+#             */
/*   Updated: 2026/01/06 12:35:07 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	a = handle_input(av);
	if (a == NULL)
		return (1);
	if (!stack_is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 1);
		if (stack_len(a) == 3)
			tiny_sort(&a, 1);
		else
			push_swap(&a, &b, 1);
	}
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
