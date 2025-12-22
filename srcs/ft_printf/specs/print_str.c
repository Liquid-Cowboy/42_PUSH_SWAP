/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:52:34 by mnogueir          #+#    #+#             */
/*   Updated: 2025/10/19 14:52:44 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	count;

	if (!str)
		return (print_str("(null)"));
	count = 0;
	while (*str)
	{
		count += print_char((int)*str);
		str++;
	}
	return (count);
}
