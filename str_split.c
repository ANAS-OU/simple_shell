#include "shell.h"

/**
 * str_split - function that take a string as input
 * and returns it as a list of words.
 * @str: input string.
 * @by: char that separats two sub-strings.
 *
 * Return: the list of words.
 */
char **str_split(char *str, char *by)
{
	char **list, *s, *word;
	unsigned int i, wc;

	wc = token_count(str, by);

	/* adding one for NULL */
	wc++;

	/* Allocating memory for pointers */
	list = malloc(wc * sizeof(char *));
	if (!list)
		return (NULL);

	s = _strdup(str);
	word = strtok(s, by);

	for (i = 0; word; i++)
	{
		list[i] = _strdup(word);
		word = strtok(NULL, by);
	}
	list[i] = NULL;
	free(s);
	return (list);
}


/**
* token_count - function that takes a string as an argment
* and count the number of sub-strings on it.
* @str: pointer to a string.
* @by: sub-strings separator.
*
* Return: number of sub-strings.
*/
unsigned int token_count(char *str, char *by)
{
	char *new_str, *word;

	unsigned int wc;

	if (!str)
		return (0);

	wc = 0;
	new_str = _strdup(str);
	word = strtok(new_str, by);
	while (word)
	{
		word = strtok(NULL, by);
		wc++;
	}

	free(new_str);
	return (wc);
}
