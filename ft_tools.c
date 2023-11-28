/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:26:18 by adrgonza          #+#    #+#             */
/*   Updated: 2022/12/05 16:27:52 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(int c)
{
	return (write(1, &c, 1));
}

int	ft_putunsigned(unsigned int nb)
{
	int	r_value;
	int	count;

	r_value = 0;
	count = 0;
	if (nb > 9)
	{
		r_value = ft_putunsigned(nb / 10);
		if (r_value == -1)
			return (-1);
		count += r_value;
	}
	if (ft_putchr(nb % 10 + '0') == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
		i++;
	return (write(1, s, i));
}

int	ft_putnbr(int nb)
{
	int	count;
	int	r_value;

	r_value = 0;
	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		if (ft_putchr('-') == -1)
			return (-1);
		count++;
		nb = nb * -1;
	}
	if (nb > 9)
	{
		r_value = ft_putnbr(nb / 10);
		if (r_value == -1)
			return (-1);
		count += r_value;
	}
	if (ft_putchr(nb % 10 + '0') == -1)
		return (-1);
	return (count + 1);
}

int	ft_puthex(unsigned long n, char ch)
{
	int		r_value;
	int		count;
	char	*s;

	count = 0;
	s = "0123456789abcdef";
	if (ch == 'X')
		s = "0123456789ABCDEF";
	if (ch == 'p')
	{
		count = ft_putstr("0x");
		if (count == -1)
			return (-1);
		ch = 0;
	}
	if (n < 16)
		return (count += ft_putchr(s[n]));
	r_value = ft_puthex(n / 16, ch);
	if (r_value == -1)
		return (-1);
	r_value += ft_puthex(n % 16, ch);
	if (r_value == -1)
		return (-1);
	return (count + r_value);
}
