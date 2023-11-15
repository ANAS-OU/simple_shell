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

	if (!strcmp(inList[0], "exit")) /* Exit the shell */
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
