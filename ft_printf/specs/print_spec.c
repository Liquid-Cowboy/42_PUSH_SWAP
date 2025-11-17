/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:57:07 by mnogueir          #+#    #+#             */
/*   Updated: 2025/10/19 14:58:38 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_spec(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += print_char(va_arg(ap, int));
	else if (spec == 's')
		count += print_str(va_arg(ap, char *));
	else if (spec == 'p')
		count += print_ptr(va_arg(ap, void *));
	else if (spec == 'd' || spec == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (spec == 'u')
		count += print_digit((long)(va_arg(ap, unsigned int)), 10);
	else if (spec == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16);
	else if (spec == 'X')
		count += print_hex_up((long)va_arg(ap, unsigned int), 16);
	else if (spec == '%')
		count += write(1, "%", 1);
	return (count);
}
