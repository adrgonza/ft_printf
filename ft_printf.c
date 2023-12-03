/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:36:06 by adrgonza          #+#    #+#             */
/*   Updated: 2023/11/28 22:14:24 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_conversions(char const s, va_list args)
{
	if (s == 'c')
		return (ft_putchr(va_arg(args, int)));
	else if (s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s == 'd' || s == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (s == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (s == 'x' || s == 'X')
		return (ft_puthex(va_arg(args, unsigned int), s));
	else if (s == 'p')
		return (ft_puthex(va_arg(args, unsigned long int), s));
	else if (s == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	ft_printf(char const *fmt, ...)
{
	va_list	args;
	int		r_value;
	int		count;

	va_start(args, fmt);
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			r_value = ft_check_conversions(*(++fmt), args);
		else
			r_value = write(1, &*fmt, 1);
		if (r_value == -1)
			return (va_end(args), -1);
		count += r_value;
		fmt++;
	}
	return (va_end(args), count);
}
