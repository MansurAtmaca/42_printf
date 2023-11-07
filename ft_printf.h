
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

char *ft_itoa(int n);
int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_hex(int n, char c);
int ft_decimal(int n, char c);
int ft_pointer(unsigned long num, int check);
int ft_unsign(unsigned int num);
#endif
