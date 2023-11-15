#include "shell.h"

/**
 * get_path - function that looks for the path
 * of the given command.
 * @cmd: the command to look for.
 *
 * Return: cmd path, or NULL if not found.
 */
char *get_path(char *cmd)
{
	char **paths, *path;
	int i, path_size;

	if (!access(cmd, X_OK))
	{
		path = strdup(cmd);
		return (path);
	}

	path = getenv("PATH");
	paths = str_split(path, ":");

	for (i = 0; paths[i]; i++)
	{
		/* the added two are for the slash and null determination character */
		path_size = _strlen(paths[i]) + _strlen(cmd) + 2;
		path = malloc(sizeof(char) * path_size);
		strcpy(path, paths[i]);
		strcat(path, "/");
		strcat(path, cmd);
		if (!access(path, X_OK))
		{
			free_list(paths);
			return (path);
		}
		free(path);
	}

	free_list(paths);
	return (NULL);
}
