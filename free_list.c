#include "shell.h"

/**
 * free_list - function that frees
 * a given double pointer list.
 * @list: double pointer list.
 *
 * Return: nothing
 */
void free_list(char **list)
{
	int i;

	if (!list)
		return;

	for (i = 0; list[i]; i++)
		free(list[i]);

	free(list);
}

