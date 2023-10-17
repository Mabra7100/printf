#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
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

    return count;
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

    return count;
}

