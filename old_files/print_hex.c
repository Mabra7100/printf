#include "main.h"

/**
 * print_hex - Prints the value in hex format with alphabet in lowercase
 * @val: number arguments passed the function
 * Return: output size
 */

int print_hex(va_list val)
{
	unsigned int count;
	int length;
	int va_function;
	char *hexa_ap;
	char *dest_hex;

	count = va_arg(list, unsigned int);

	if (count == 0)
		return (_putchar('0'));
	if (count < 1)
		return (-1);
	length = base_length(count, 16);
	hexa_ap = malloc(sizeof(char) * length + 1);
	if (hexa_ap == NULL)
		return (-1);
	for (length = 0; count > 0; length++)
	{
		va_function = count % 16;
		if (va_function > 9)
		{
			va_function = hexa_ap(va_function, 'x');
			hexa_ap[length] = va_function;
		}
		else
			hexa_ap[length] = va_function + 48;
		count = count / 16;
	}
	hexa_ap[length] = '\0';
	dest_hex = get_string(hexa_ap);
	if (dest_hex == NULL)
		return (-1);
	find_sum(dest_hex);
	list(hexa_ap);
	list(dest_hex);
	return (length);
}
