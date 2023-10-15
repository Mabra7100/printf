#include "main.h"
/**
* print_bin - converts num to binary
* @va: decimal num
* Return: printed num of chars
*/
int print_bin(va_list va)
{
	unsigned int last, sum, p, value, s, count;
	int flag = 0;

	s = va_arg(va, unsigned int);
	if (s != 0)
	{
		count = s;
		last = 0;
		while (count != 0)
		{
			count /= 2;
			last++;
		}
		sum = 1;
		for (p = 1; p <= last - 1; p++)
			sum *= 2;
		for (p = 1; p <= last; p++)
		{
			value = s / sum;
			_putchar(value + '0');
			flag++;
			s -= value * sum;
			sum /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (flag);
}

