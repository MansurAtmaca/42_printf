/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:37:30 by matmaca           #+#    #+#             */
/*   Updated: 2023/11/07 16:42:56 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
		return (write (1, "(null)", 6));
	while (str[i] != '\0')
	{
		ft_putchar(str[i++]);
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free (str);
	return (len);
}

int	ft_hex(unsigned int n, char c)
{
	int	len;
	int check;

	len = 0;

	if (!n)
		return (write(1, "0", 1));
	if (n < 0)
		n *= -1;
	if (n >= 16)
	{
		check = ft_hex(n / 16, c);
		if (check == -1)
			return (-1);
		len += check;
	}

	if (c == 'x')
		ft_putchar("0123456789abcdef"[n % 16]);
	if (c == 'X')
		ft_putchar("0123456789ABCDEF"[n % 16]);
	return (len + 1);
}

int	ft_decimal(int n, char c)
{
	int	len;

	len = 0;
	if (n >= 10)
		len = ft_decimal(n / 10, c);
	if (c == 'i')
	{
		ft_putchar("0123456789"[n % 10]);
	}
	return (len + 1);
}

int	ft_pointer(unsigned long int num, int check)
{
	int	i;

	i = 0;
	if (check)
	{
		write(1, "0x", 2);
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

	i = 0;
	if (num >= 10)
		i += ft_unsign(num / 10);
	ft_putchar("0123456789"[num % 10]);
	return (i + 1);
}
