#include "shell_header.h"
#include <string.h>

/**
 * check_token - checks to see if there are more arguments after first
 * @cmd: command passed
 * @args: arguments passed
 *
 * Return: nothing
 */
void check_token(char *cmd, char *args[])
{
	pid_t pid;
	int status;

	if (strtok(NULL, " ") != NULL)
	{
		_puts("Too many arguments passed\n");
		return;
	}
	pid = check_fork();
	if (pid == 0)
	{
		execve(cmd, args, NULL);

		perror("execve failed");
		free(cmd);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
