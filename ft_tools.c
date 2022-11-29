#include "ft_printf.h"

int ft_putunsigned(unsigned int a)
{
	if (a > 9)
		ft_putunsigned(a / 10);
	return (ft_putchr(a % 10 + '0'));
}

int	ft_putchr(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	int	c;

	c = 0;
	while (s[c])
		c++;
	return (write(1, s, c));
}

int	ft_putnbr(int nb)
{
	char	n;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return 0;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
	{
		n = '0' + nb;
		write(1, &n, 1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (0);
}