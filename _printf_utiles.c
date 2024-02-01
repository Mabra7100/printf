#include "main.h"

void	_puthex(unsigned int n, char *base, int *counter)
{
	if (n >= 16)
	{
		_puthex(n / 16, base, counter);
		_putchar(base[n % 16], counter);
	}
	else if (n < 16)
		_putchar(base[n], counter);
}
static	void	do_putptr(unsigned long n, char *base, int *counter)
{
	if (n >= 16)
	{
		do_putptr(n / 16, base, counter);
		_putchar(base[n % 16], counter);
	}
	else if (n < 16)
		_putchar(base[n], counter);
}

void	_putptr(unsigned long n, char *base, int *counter)
{
	_putstr("0x", counter);
	do_putptr(n, base, counter);
}