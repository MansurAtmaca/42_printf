#include "ft_printf.h"

int check_format(char c)
{
    if(c == 'c' || c == 's' || c == 'p' || c == 'i' 
        || c == 'd' || c == 'u' || c == 'x' || c == 'X' || c == '%' )
        return (1);
    else 
    return (0);
}
int formats(va_list args, char c)
{
    if (c == 'c')
        return (ft_putchar(va_arg(args, int))); 
    if (c == 's')
        return (ft_putstr(va_arg(args, char *)));
    if (c == 'd')
        return (ft_putnbr(va_arg(args, int)));
    return (0);
}
int ft_printf(const char *format,...)
{
    va_list args;
    va_start(args,format);
    int i;
    int len;

    i = 0;
    len = 0;

    while (format[i] != '\0')
    {
        if(format[i] == '%' && check_format(format[i + 1]))
        {
            len += formats(args,format[i + 1]); 
        }
          i++;
    }

    va_end(args);
    return (len);
    
}

int main()
{
    ft_printf("%d",453233);
}