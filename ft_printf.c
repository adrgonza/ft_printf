/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:36:06 by adrgonza          #+#    #+#             */
/*   Updated: 2022/11/25 14:38:12 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_check_conversions(char s, va_list args)
{
    if (s == 'c')
        return (ft_putchr(va_arg(args, int)));
    else if (s == 's')
        return (ft_putstr(va_arg(args, char *)));
    else if (s == 'p')
        return (0);
    else if (s == 'd' || s == 'i')
        return (ft_putnbr(va_arg(args, int)));
    else if (s == 'u')
        return (ft_putunsigned(va_arg(args, unsigned int)));
    else if (s == 'x' || s == 'X')
        return (0);
    else if (s == '%')
        return (write(1, "%", 1));
    return (0);
}

int	ft_printf(char const *s, ...)
{
    va_list args;
    int a;

    va_start(args, s);
    a = 0;
    while(*s)
    {
        if (*s == '%')
            ft_check_conversions(*(++s), args);
        else
            write(1, &*s, 1);
        s++;
    }
    va_end(args);
    return (0);
}

int main(void)
{
    ft_printf("%u", 3999435334);
    printf("\n%u", 3999435334);
}
