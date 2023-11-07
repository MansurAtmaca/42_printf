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
	int		res;

	va_start(args, format);
	i = 0;
	len = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += formats(args, format[i]);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
#include <stdio.h>
int main()
{
	int i=ft_printf("\001\002\007\v\010\f\r\n");
	printf("sonuc: %d",i);
}
