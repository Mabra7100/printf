#include "main.h"
/**
* print_unsig - prints unsigned number
* @d: unsigned num
* Descriptions: The unsigned number printed with putchar
* Return: output size
*/
int print_unsig(va_list d)
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
			sum /= 10;
			length++;
		}
		dest = 1;
		for (p = 1; p <= length - 1; p++)
			dest *= 10;
		for (p = 1; p <= length; p++)
		{
			value = s\s / dest;
			_putchar(value + '0');
			num++;
			s -= value * dest;
			dest /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (num);
}
