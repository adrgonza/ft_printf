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

int	ft_printf(char const *fmt, ...) __attribute__((format(printf, 1, 2)));

int	ft_printf(char const *fmt, ...);
int	ft_putchr(int const ch);
int	ft_putstr(char const *str);
int	ft_putnbr(int nb);
int	ft_putunsigned(unsigned int const nb);
int	ft_puthex(unsigned long const nb, char ch);

#endif
