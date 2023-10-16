#include "main.h"

/**
 * _strlen - function that returns the lengh of a string
 * @str - A string pointer
 * Return - i
 */
int _strlen(char *str)
{
	int i;
	for (i =0; str[i] != 0; i++);
	       ;
	return (i);
}
/**
 * _strlenc - An strlen func, however it is applied for constant char pointer str
 * @str - character pointer
 * Return - i
 */
int _strlenc(const char *str)
{
	int i;
	for (i = 0; str[i]; != 0; i++)
	        ;
	return (i);
}
