#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int     _printf(const char *format, ...);
void    checkformat(char c, va_list args, int *counter);
void    _putchar(char c, int *counter);
void    _putstr(char *str, int *counter);
void    _putnbr(long nb, int *counter);
void    _puthex(unsigned int n, char *base, int *counter);
void	_putptr(unsigned long n, char *base, int *counter);


#endif
