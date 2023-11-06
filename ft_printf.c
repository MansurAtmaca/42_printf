#include "ft_printf.h"
int ft_putchar(char c)
{
    return (write(1, &c, 1));
}
/*  static int check_format(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'i' || c == 'd' || c == 'u' || c == 'x' || c == 'X' || c == '%')
        return (1);
    else
        return (0);
} */ 
static int formats(va_list args, char c)
{
    if (c == 'c')
        return (ft_putchar(va_arg(args, int)));
    if (c == 's')
        return (ft_putstr(va_arg(args, char *)));
    if (c == 'd')
        return (ft_putnbr(va_arg(args, int)));
    if (c == 'x' || c == 'X')
        return (ft_hex(va_arg(args, int), c));
    if (c == 'i')
        return (ft_decimal(va_arg(args, int), c));
    if (c == '%')
        return (write(1, "%%", 1));
    if (c == 'p')
        return (ft_pointer(va_arg(args, unsigned long), 1));
    if (c == 'u')
        return (ft_unsign(va_arg(args, unsigned int)));
    return (-1);
}
int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int i;
    int len;

    i = 0;
    len = 0;

    while (format[i] != '\0')
    { 
        if (format[i] == '%')
        {
            i++;
            len += formats(args, format[i]);
        }
        else if (format[i] != '\0')
        {
            len += ft_putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return (len);
}
int main() {

 ft_printf("%cs%cs%c\n", 'c', 'b', 'a');
 ft_printf("%cc%cc%c\n", 'a', '\t', 'b');
}