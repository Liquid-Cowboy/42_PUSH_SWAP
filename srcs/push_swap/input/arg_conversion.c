/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:35:21 by mnogueir          #+#    #+#             */
/*   Updated: 2026/01/06 11:42:58 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

//Functions used in the conversion of arguments
//(as strings) to nodes in a linked list.

t_stack_node	*handle_input(char **arg)
{
	int				i;
	char			**ar;
	t_stack_node	*stack;

	i = 1;
	ar = ft_split(arg[i]);
	i++;
	while (arg[i])
		ar = cat_array(ar, ft_split(arg[i++]));
	stack = init_stack(ar);
	if (ar)
		free_all(ar);
	return (stack);
}

void	cat_string(char **ar, char **dest, char **src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ar[i])
	{
		dest[i] = create_str(dest, ar[i]);
		i++;
	}
	while (src[j])
		dest[i++] = create_str(dest, src[j++]);
	dest[i] = NULL;
}

char	**cat_array(char **ar, char **src)
{
	int		i;
	int		j;
	char	**dest;

	i = 0;
	j = 0;
	while (ar[i])
		i++;
	while (src[j])
		j++;
	dest = (char **) malloc (sizeof(char *) * (i + j + 1));
	if (!dest)
	{
		free_all(src);
		free_all(ar);
		return (NULL);
	}
	cat_string(ar, dest, src);
	free_all(src);
	free_all(ar);
	return (dest);
}

long long	ft_atol(char *str)
{
	int			i;
	long long	nbr;
	int			is_negative;

	i = 0;
	nbr = 0;
	is_negative = 0;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	while (str[i])
		nbr = nbr * 10 + (str[i++] - '0');
	if (is_negative)
		nbr = -nbr;
	return (nbr);
}
