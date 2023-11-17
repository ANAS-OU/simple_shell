#include "shell.h"

/**
* main - program that work as a simple shell
* @argc: argments count.
* @argv: program agrs list.
*
* Return: 0 always
*/
int main(int argc, char **argv)
{
	char *input;
	size_t input_len;
	(void)argc;

	input = NULL;
	input_len = 0;
	while (1)
	{
	/* Don't print in No-Intractive mode */
	if (isatty(STDIN_FILENO))
		printf("($) ");

	input_len = getline(&input, &input_len, stdin);

	/* Handling input error and EOF */
	if ((int)input_len == -1)
		free(input), exit(0);
	if (execute_cmd(input, argv[0]))
		break;
	}
	free(input);
	return (0);
}
