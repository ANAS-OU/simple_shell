#include "shell.h"

/**
* substr_counter - function that take a string as argment
* and count the number of sub-strings on it.
* @str: pointer to a string.
* @by: sub-strings separator.
*
* Return: number of sub-strings.
*/
unsigned int substr_counter(char *str, char *by)
{
	char *new_str, *word;

	unsigned int wc;

	if (!str)
		return (0);

	wc = 0;
	new_str = strdup(str);
	word = strtok(new_str, by);
	while (word)
	{
		word = strtok(NULL, by);
		wc++;
	}

	free(new_str);
	return (wc);
}
