/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:25:02 by adrgonza          #+#    #+#             */
/*   Updated: 2022/12/05 16:26:00 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(char const *s, ...) __attribute__((format(printf, 1, 2)));

int	ft_printf(char const *s, ...);
int	ft_putchr(int c);
int	ft_putstr(const char *s);
int	ft_putnbr(int nb);
int	ft_putunsigned(unsigned int a);
int	ft_puthex(unsigned long n, char c);

#endif
