#include "ft_printf.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmaca <matmaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:37:30 by matmaca           #+#    #+#             */
/*   Updated: 2023/10/26 13:39:51 by matmaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	find_digit(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			digit;
	char		*string;
	long		num;

	num = (long)n;
	digit = find_digit(num);
	if (num < 0)
	{
		num *= -1;
		digit += 1;
	}
	string = (char *)malloc(sizeof(char) * digit + 1);
	if (!string)
		return (NULL);
	string[digit] = '\0';
	while (digit > 0)
	{
		string[--digit] = (num % 10) + 48;
		num /= 10;
	}
	if (n < 0)
		string[0] = '-';
	return (string);
}


int ft_putstr(char *str)
{
    int i;
    int len;

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
/* int ft_putnbr(int n)
{
    int len;

    len = 0;
    if (n == -2147483648)
    {
        return (ft_putstr("-2147483648"));
    }
    else if (n < 0)
    {
        ft_putchar('-');
        ft_putnbr(n * -1);
    }
    else if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + 48);
    }
    else if (n <= 9)
    {
        ft_putchar(n % 10 + 48);
    }
    return (len + 1);
} */

int ft_putnbr(int n)
{
    char *str;

    str = ft_itoa(n);
    return(ft_putstr(str));
}
int ft_hex(int n, char c)
{
    int len;

    len = 0;
    if (n >= 16)
        len = ft_hex(n / 16, c);
    if (c == 'x')
    {
        ft_putchar("0123456789abcdef"[n % 16]);
    }
    if (c == 'X')
    {
        ft_putchar("0123456789ABCDEF"[n % 16]);
    }
    return (len + 1);
}
int ft_decimal(int n, char c)
{
    int len;

    len = 0;
    if (n >= 10)
        len = ft_decimal(n / 10, c);
    if (c == 'i')
    {
        ft_putchar("0123456789"[n % 10]);
    }
    return (len + 1);
}
int ft_pointer(unsigned long num, int check)
{
    int i;

    if (!num)
        return (write (1, "(null)", 6));
    i = 0;
    if (check){
        write(1, "0x", 2);
        i += 2;
    }
i += ft_hex(num,'x');
      return(i);
}
int ft_unsign(unsigned int num)
{
    return (ft_putnbr(num));
}