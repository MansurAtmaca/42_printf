/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:37:30 by matmaca           #+#    #+#             */
/*   Updated: 2023/11/08 14:00:12 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
	{
		if ((write(1, &str[i], 1)) < 0)
			return (-1);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_hex(unsigned int n, char c)
{
	int	len;
	int	check;

	len = 0;
	if (n >= 16)
	{
		check = ft_hex(n / 16, c);
		if (check == -1)
			return (-1);
		len += check;
	}
	if (c == 'x')
	{
		if (ft_putchar("0123456789abcdef"[n % 16]) < 0)
			return (-1);
	}
	if (c == 'X')
	{
		if (ft_putchar("0123456789ABCDEF"[n % 16]) < 0)
			return (-1);
	}
	return (len + 1);
}

int	ft_pointer(unsigned long int num, int check)
{
	int	i;

	i = 0;
	if (check)
	{
		if (write(1, "0x", 2) < 0)
			return (-1);
		i += 2;
	}
	if (num >= 16)
		i += ft_pointer(num / 16, 0);
	ft_putchar("0123456789abcdef"[num % 16]);
	return (i + 1);
}

int	ft_unsign(unsigned int num)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (num >= 10)
	{
		tmp += ft_unsign(num / 10);
		if (tmp < 0)
			return (-1);
		i += tmp;
	}
	if (ft_putchar("0123456789"[num % 10]) < 0)
		return (-1);
	return (i + 1);
}
