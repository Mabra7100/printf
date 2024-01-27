#include "main.h"
void _putnbr(int nb, int *counter)
{
    if (nb == -2147483648)
        _putstr("-2147483648", counter);
    else if (nb < 0)
    {
        nb = nb * -1;
        _putchar('-', counter);
        _putnbr(nb, counter);
    }
    else if (nb >= 10)
    {
        _putnbr(nb / 10, counter);
        _putnbr(nb % 10, counter);
    }
    else
        _putchar(nb + '0', counter);
}

void _putstr(char *str, int *counter)
{
    int i;

    i = -1;
    while(str[++i])
        _putchar(str[i], counter);
}
void _putchar(char c, int *counter)
{
    write(1,&c,1);
    (*counter)++;
}
void checkformat(char c, va_list args, int *counter)
{
    if (c == '%')
        _putchar('%', counter);
    if (c == 's')
        _putstr(va_arg(args, char *),counter);
    if (c == 'c')
        _putchar(va_arg(args, int), counter);
    if (c == 'd' || c == 'i')
        _putnbr(va_arg(args, int), counter);
}
int _printf(const char *format, ...)
{
    int i;
    int counter;
    va_list args;

    i = 0;
    counter = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
            checkformat(format[++i], args, &counter);
        else
            _putchar(format[i], &counter);
        i++;
    }
    return (counter);
}
