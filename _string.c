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


/**
 * _strcat - function that concatenates two strings.
 * @dest: pointer param 1
 * @src: pointer param 2
 *
 * Return: pointer contains two strings.
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*dest)
		dest++;

	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (p);
}


/**
 * _strcpy - function that copies the string pointed to by src,
 * including the terminating null byte (\0), to the buffer
 * pointed to by dest.
 * @dest: pointer param 1.
 * @src: pointer param 2.
 *
 * Return: string.
 */
char *_strcpy(char *dest, char *src)
{
	char *_depart = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (_depart);
}


/**
 * _strcmp - function that compares two strings.
 * @s1: pointer param 1.
 * @s2: pointer param 2.
 *
 * Return: if s1 equal s2 it returns 0,
 * negative if s1 less than s2,
 * positive if s2 greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	unsigned char c1, c2;

	do {
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (c1 == '\0')
			return (c1 - c2);
	} while (c1 == c2);

	return (c1 - c2);
}

/**
 * _strdup - function that returns a pointer to a newly allocated
 * space in memory, which contains a copy of a given string.
 * @str: Original string.
 *
 * Return: Copy string.
 */
char *_strdup(char *str)
{
	char *s;
	int i, size;

	if (str == NULL)
		return (NULL);
	size = _strlen(str) + 1;
	s = malloc(size * sizeof(char));
	if (s == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		s[i] = str[i];

	return (s);
}
