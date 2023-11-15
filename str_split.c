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

	wc = substr_counter(str, by);

	/* adding one for NULL */
	wc++;

	/* Allocating memory for pointers */
	list = malloc(wc * sizeof(char *));
	if (!list)
		return (NULL);

	s = strdup(str);
	word = strtok(s, by);

	for (i = 0; word; i++)
	{
		list[i] = strdup(word);
		word = strtok(NULL, by);
	}
	list[i] = NULL;
	free(s);
	return (list);
}
