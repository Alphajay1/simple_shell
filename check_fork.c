#include "shell_header.h"

/**
 * check_fork - checks if the fork process fails
 *
 * Return: pid of child process on success, -1 if failed
 */
pid_t check_fork(void)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	return (pid);
}
