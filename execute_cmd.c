#include "shell.h"

/**
* execute_cmd - function that executes
* the given commands.
* @input: prompt input.
* @pgm: shell program name.
*
* Return: 0 - still in the program
* 1 - exit with status.
*/
int execute_cmd(char *input, char *pgm)
{
	char **inList, *path;
	int status;
	pid_t child_pid;

	/* Slice input to pieces and put them to a list */
	inList = str_split(input, " \t\n");

	/* Skipping case */
	if (!inList[0])
	{
		free_list(inList);
		return (0);
	}
	if (!_strcmp(inList[0], "exit")) /* Exit the shell */
	{
		free_list(inList);
		return (1);
	}
	path = get_path(inList[0]); /* Check the existent of the cmd's binary file */
	if (!path)
	{
		print_error(pgm, inList[0]);
		free_list(inList);
		return (0);
	}

	/* Creating new process to execute the given cmd */
	child_pid = fork();
	if (child_pid == 0) /* Child process */
	{
		execve(path, inList, environ);
		exit(1);
	}
	else /* Parent process */
			wait(&status);

	/* Free the allocated memory*/
	free_list(inList);
	free(path);
	return (0);
}


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
		path = _strdup(cmd);
		return (path);
	}

	path = getenv("PATH");
	paths = str_split(path, ":");

	for (i = 0; paths[i]; i++)
	{
		/* the added two are for the slash and null determination character */
		path_size = _strlen(paths[i]) + _strlen(cmd) + 2;
		path = malloc(sizeof(char) * path_size);
		_strcpy(path, paths[i]);
		_strcat(path, "/");
		_strcat(path, cmd);
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
