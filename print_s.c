#include "main.h"

/**
 * printf_string - function that prints a string
 * val - value aguments
 * Return - length of a string
 */
int printf_string(va -list arg)
}

	char *str;
	int i;
	int len;

	str = va_lis(arg, char *);
	if (str ==NULL)
   {
   
	str = "(null)";
	len = _strlen(str);
	for (i = 0; i < len; i++)
		_putchar(str[i]);
	return (len);
   }
   else
   { 
	len = _strlen(str);
	for (i = 0, i < len, i++)
		_putchar(str[i]);
	return (len);
   }
}



