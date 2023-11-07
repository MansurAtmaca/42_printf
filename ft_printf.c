/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:22:37 by matmaca           #+#    #+#             */
/*   Updated: 2023/11/07 17:01:57 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
		return (write(1, &c, 1));
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
	if (c == '%')
		return (write(1, "%%", 1));
	if (c == 'p')
		return (ft_pointer(va_arg(args, unsigned long int), 1));
	if (c == 'u')
		return (ft_unsign(va_arg(args, unsigned int)));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	int tmp;

	va_start(args, format);
	i = 0;
	len = 0;
	tmp = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			tmp = formats(args, format[i]);
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		else
		{
			tmp = ft_putchar(format[i]);
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*  */
