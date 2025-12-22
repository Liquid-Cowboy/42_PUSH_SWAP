/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:26:41 by mnogueir          #+#    #+#             */
/*   Updated: 2025/10/19 14:55:23 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start (ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_spec(*++format, ap);
		else
			count += write (1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
