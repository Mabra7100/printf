#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable number of arguments
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *ptr;

if (format == NULL)
{
return (-1);
}


va_start(args, format);

for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr == '%' && *(ptr + 1) != '\0')
{
ptr++;
count += handle_format(*ptr, args);
}
else
{
write(1, ptr, 1);
count++;
}
}

va_end(args);

return (count);
}

/**
 * handle_format - Handle conversion specifiers
 * @specifier: Conversion specifier
 * @args: Variable arguments list
 *
 * Return: Number of characters printed for the specifier
 */
int handle_format(char specifier, va_list args)
{
char c;
char *str;
int count = 0;
int num;

switch (specifier)
{
case 'c':
c = va_arg(args, int);
write(1, &c, 1);
count++;
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
while (*str)
{
write(1, str, 1);
str++;
count++;
}
break;
case 'd':
case 'i':
num = va_arg(args, int);
count += print_number(num);
break;
case '%':
write(1, "%", 1);
count++;
break;
default:
write(1, "%", 1);
write(1, &specifier, 1);
count += 2;
break;
}

return (count);
}

/**
 * print_number - Print an integer
 * @n: Integer to print
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
char buffer[20];
int count = 0;
int i = 0;

if (n < 0)
{
write(1, "-", 1);
count++;
n = -n;
}

if (n == 0)
{
write(1, "0", 1);
count++;
}
else
{
while (n != 0)
{
buffer[i++] = '0' + n % 10;
n /= 10;
}

while (--i >= 0)
{
write(1, &buffer[i], 1);
count++;
}
}

return (count);
}
