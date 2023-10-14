#include "main.h"

/**
 * printf_int: Function that prints an integer
 * @args: The arguments to print
 * Return: number of chars 
 */
int print_int(va_list args);
{

	int d = va_num(args, int);
        int sum, end = d % 10, value, list = 1;
	int i = 1;

	d = d / 10;
	sum = d;

	if (end < 0)
	{
		_putchar('_');
		sum = -sum;
		d = -d;
		end = -end;
		i++;
	}
	if (sum > 0)
	{
		while (sum / 10 ! =0)
		{
			list = list * 10;
			sum = sum / 10;
		}
	        sum = d;
		while (list > 0)
		{
			value = sum / list;
			_putchar(value + '0');
			sum = sum - (value * list);
			list = list / 10;
			i++
		}
         }
          _putchar(end + '0');

	  return (i);
}
#include "main.h"
/**
 * printf_dec - A function that prints decimal
 * @args - The arguments to print
 * Return - number of chars
 */
int print_dec(va_list args)

	int d = va_num(args, int);
{       int sum, end = d % 10, value, list = 1;
        int i = 1;

        d = d / 10;
        sum = d;

        if (end < 0)
        {
                _putchar('_');
                sum = -sum;
                d = -d;
                end = -end;
                i++;
	}
        is (sum > 0)
	{
		while (sum / 10 != 0)
		{
			list = list * 10;
			sum = sum / 10;
		}
		sum = d
			while (list > 0)
			{
				value = sum / list;
				_putchar(value + '0')
				sum = sum - (value * list);
				list = list / 10;
				i++
			}
	}
	_putchar(end + '0');

	return (i);
}
	


