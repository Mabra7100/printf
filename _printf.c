#include "main.h"

/**
 *_printf - its printf like function
 *
 *@format: Arguments
 *
 *Return: return chars
 */

int _printf(const char *format, ...)
{
	int chars = 0;
	va_list ap;
	va_start(ap, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
            case 'c':
            	{
            		char temp = (char)va_arg(ap, int);
            		chars += write(1, &temp, 1);
				}
                break;

            case 's':
                {
                    char *str = va_arg(ap, char*);
                    chars += write(1, str, strlen(str));
                }
                break;
            default:
                chars += write(1, format, 1);
            }
        }
        else
        {
            chars += write(1, format, 1);
        }

        format++;
    }

    va_end(ap);

    return chars;
}