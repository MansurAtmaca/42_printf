/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:22:37 by matmaca           #+#    #+#             */
/*   Updated: 2023/11/08 13:59:35 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_check_flag(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 'u' || c == '%'
		|| c == 's' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}

static int	formats(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'x' || c == 'X')
		return (ft_hex(va_arg(args, int), c));
	if (c == 'p')
		return (ft_pointer(va_arg(args, unsigned long int), 1));
	if (c == 'u')
		return (ft_unsign(va_arg(args, unsigned int)));
	if (c == '%')
	{
		if (ft_putchar('%') < 0)
			return (-1);
		return (1);
	}
	return (-1);
}

int	check(const char *format, va_list args, int res)
{
	int		tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_check_flag(format[i + 1]))
		{
			tmp = formats(args, format[++i]);
			if (tmp == -1)
				return (-1);
			res += tmp;
		}
		else
		{
			tmp = ft_putchar(format[i]);
			if (tmp == -1)
				return (-1);
			res += tmp;
		}
		i++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = 0;
	res = check(format, args, res);
	if (res < 0)
		return (-1);
	va_end(args);
	return (res);
}
