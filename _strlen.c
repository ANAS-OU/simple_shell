/* _strlen.c */
#include "shell.h"

/**
* _strlen - function that returns the length of
* a given string.
* @str: pointer to the given string.
*
* Return: the string length.
*/

int _strlen(char *str)
{
	int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}
