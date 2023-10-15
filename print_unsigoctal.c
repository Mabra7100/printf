#include "main.h"
/**
* print_unsigoctal - changes unsigned int arg to unsigned octal
* @u: unsigned to be chaged
* Descriptions: prints unsigned octal
* Return: output size
*/
int print_unsigoctal(va_list u)
{
	unsigned int length, dest, p, value, s, sum;
	int num = 0;

	s = va_arg(u, unsigned int);
	if (s != 0)
	{
		sum = n;
		length = 0;
		while (sum != 0)
		{
			sum /= 8;
			length++;
		}
		dest = 1;
		for (p = 1; p <= length - 1; p++)
			dest *= 8;
		for (p = 1; p <= length; p++)
		{
			value = s / dest;
			_putchar(value + '0');
			num++;
			s -= value * dest;
			dest /= 8;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (num);
}
