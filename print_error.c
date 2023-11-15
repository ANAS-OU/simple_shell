#include "shell.h"

/**
 * print_error - function that used to print to
 * the stderr owr errors messages.
 * @pgm: shell program name.
 * @cmd: failed command name.
 *
 * Return: nothing
 */
void print_error(char *pgm, char *cmd)
{
	char buffer[BUFSIZE];

	_strcpy(buffer, pgm);
	_strcat(buffer, ": 1: ");
	_strcat(buffer, cmd);
	_strcat(buffer, ": not found\n");

	/* printing the error */
	write(STDERR_FILENO, buffer, _strlen(buffer));
}
