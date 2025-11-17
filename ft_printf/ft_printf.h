/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnogueir <mnogueir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:51:36 by mnogueir          #+#    #+#             */
/*   Updated: 2025/10/19 14:56:34 by mnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_spec(char spec, va_list ap);
int	print_char(int c);
int	print_str(char *str);
int	print_ptr(void *ptr);
int	print_digit(long n, int base);
int	print_hex_up(long n, int base);

#endif
