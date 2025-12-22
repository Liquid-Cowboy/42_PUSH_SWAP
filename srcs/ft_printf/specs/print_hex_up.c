/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:18:18 by mnogueir          #+#    #+#             */
/*   Updated: 2025/10/19 15:18:36 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_up(long n, int base)
{
	int		count;
	char	*base_digits;

	base_digits = "0123456789ABCDEF";
	count = 0;
	if (n >= base)
		count += print_hex_up(n / base, base);
	count += print_char(base_digits[n % base]);
	return (count);
}
