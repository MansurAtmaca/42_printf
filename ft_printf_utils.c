#include "ft_printf.h"

int ft_putstr(char *str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i++]);
        len++;
    }
    return (len);
}
int ft_putnbr(int n)
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