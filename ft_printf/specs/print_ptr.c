/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:49:52 by mnogueir          #+#    #+#             */
/*   Updated: 2025/10/19 15:18:47 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ulong(unsigned long n, unsigned int base)
{
	int		count;
	char	*base_digits;

	base_digits = "0123456789abcdef";
	count = 0;
	if (n >= base)
		count += print_ulong(n / base, base);
	count += print_char(base_digits[n % base]);
	return (count);
}

int	print_ptr(void *ptr)
{
	int	count;

	if (!ptr)
		count = print_str("(nil)");
	else
	{
		count = print_str("0x");
		count += (print_ulong((unsigned long)ptr, 16));
	}
	return (count);
}
