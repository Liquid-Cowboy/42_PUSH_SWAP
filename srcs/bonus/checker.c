/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:34:27 by mnogueir          #+#    #+#             */
/*   Updated: 2026/01/06 11:16:19 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "get_next_line.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	parse_command(t_stack_node **a, t_stack_node **b,
		char *command, int print)
{
	if (!ft_strcmp(command, "sa\n"))
		sa(a, print);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, print);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, print);
	else if (!ft_strcmp(command, "pa\n"))
		pa(a, b, print);
	else if (!ft_strcmp(command, "pb\n"))
		pb(a, b, print);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, print);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, print);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, print);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, print);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, print);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, print);
	else
		error_clear(a, NULL);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*input;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	a = handle_input(av);
	if (a == NULL)
		return (1);
	input = get_next_line(0);
	while (input)
	{
		parse_command(&a, &b, input, 0);
		free(input);
		input = get_next_line(0);
	}
	if (stack_is_sorted(a) && stack_len(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
