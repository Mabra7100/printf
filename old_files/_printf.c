#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
  * get_function - function that search formats for printf
  * @format: format num of other values and prints a string
  * Return: NULL
  */
int (*get_function(const char *format))(va_list)
{
	unsigned int i = 0;
	code_f get_f[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_dec},
		{"r", print_rev},
		{"b", print_bin},
		{"u", print_unsig},
		{"o", print_octal},
		{"x", print_x},
		{"X", print_X},
		{"R", print_rot13},
		{NULL, NULL}
	};

	while (get_f[i].ab)
	{
		if (get_f[i].ab[0] == (*format))
			return (get_f[i].f);
		i++;
	}
	return (NULL);
}
/**
  * _printf - A function that produces an output
  * @format: format num of other values and prints a string
  * Return: output  size
  */
int _printf(const char *format, ...)
{
	va_list exp;
	int (*f)(va_list);
	unsigned int i = 0, dest = 0;

	if (format == NULL)
		return (-1);
	va_start(exp, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			dest++;
			i++;
		}
		if (format[i] == '\0')
			return (dest);
		f = get_function(&format[i + 1]);
		if (f != NULL)
		{
			dest += f(exp);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		dest++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(exp);
	return (dest);
}
