#include "shell_header.h"
/**
 * exec_cmd - executes command
 * @command: command to be passed
 *
 * Return: Nothing
 */
void exec_cmd(char *command)
{
	char *args[1024];
	pid_t pid;
	int status;
	char *cmd = strtok(command, " ");

	args[0] = cmd, args[1] = NULL;
	if (!isatty(fileno(stdin)))
	{
		pid = check_fork();
		if (pid == 0)
			execve(cmd, args, NULL);
		if (execve(cmd, args, NULL) == -1)
		{
			free(command);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, 0);
	}
	if (strtok(NULL, " ") != NULL)
	{
		printf("Too many arguments passed\n");
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
		waitpid(pid, &status, 0);
}
