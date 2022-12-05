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
	write(1, &c, 1);
	return (1);
}

int	ft_putunsigned(unsigned int a)
{
	int	b;

	b = 0;
	if (a > 9)
		b += ft_putunsigned(a / 10);
	return (b += ft_putchr(a % 10 + '0'));
}

int	ft_putstr(const char *s)
{
	int	c;

	if (!s)
		return (write(1, "(null)", 6));
	c = 0;
	while (s[c])
		c++;
	return (write(1, s, c));
}

int	ft_putnbr(int nb)
{
	int	a;

	a = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		a += ft_putchr('-');
		nb = nb * -1;
	}
	if (nb > 9)
		a += ft_putnbr(nb / 10);
	return (a += ft_putchr(nb % 10 + '0'));
}

int	ft_puthex(unsigned long n, char c)
{
	int		a;
	char	*s;

	a = 0;
	if (c == 'X')
		s = "0123456789ABCDEF";
	else
		s = "0123456789abcdef";
	if (c == 'p')
	{
		a += ft_putstr("0x");
		c = 0;
	}
	if (n < 16)
		a += ft_putchr(s[n]);
	else
	{
		a += ft_puthex(n / 16, c);
		a += ft_puthex(n % 16, c);
	}
	return (a);
}
