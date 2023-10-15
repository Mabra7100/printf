#include "main.h"

/**
 * _printf - Prints chars and values
 * @format: print a string
 *
 * Return: number of character to  print
 */
int _printf(const char *format, ...)
{
	va_list pa;
	int length = 0;

	if (format == NULL)
		return (-1);

	va_start(pa, format);

	length = _print_format(format, pa);
	va_end(pa);
	return (length);
}
