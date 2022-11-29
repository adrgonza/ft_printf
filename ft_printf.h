#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(char const *s, ...);
int	ft_putchr(char c);
int	ft_putstr(const char *s);
int ft_putnbr(int nb);
int ft_putunsigned(unsigned int a);


#endif