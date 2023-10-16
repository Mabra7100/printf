#include "main.h"

/**
 * printf_char - prints a series of chars
 * @val - variable argument
 * Return - 1.
 */
int printf_char(va_list arg)
{
	char str;
	
	str = va_lis(arg, int);
	_putchar(str);
	return (1);
}



