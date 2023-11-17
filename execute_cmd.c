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

	if (!inList[0]) /* Skipping case */
	{
		free_list(inList);
		return (0);
	}
	if (!_strcmp(inList[0], "exit")) /* Exit the shell */
	{
		free_list(inList);
		return (1);
	}
	if (customize_env(inList))
		return (0);

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
	}
	else /* Parent process */
			wait(&status);

	/* Free the allocated memory*/
	free_list(inList), free(path);
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
		path = malloc(sizeof(char *) * path_size);
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


/**
 * customize_env - function that work to set and unset
 * environment variables.
 * @inList: double list pointer.
 *
 * Return: 1 - then it works, 0 - Otherwise.
 */
int customize_env(char **inList)
{
	if (!strcmp(inList[0], "setenv"))
	{
		if (setenv(inList[1], inList[2], 1) == -1)
			perror("Failed adding a new environment variable!");

		free_list(inList);
		return (1);
	}
	else if (!strcmp(inList[0], "unsetenv"))
	{
		if (unsetenv(inList[1]) == -1)
			perror("Failed unset environment variable!");

		free_list(inList);
		return (1);
	}
	return (0);
}
