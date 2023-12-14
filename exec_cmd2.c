#include "shell_header.h"
/**
 * exec_cmds - executes command
 * @command: command to execute
 *
 * Return: nothing
 */
void exec_cmds(char *command)
{
	pid_t pid = getpid();
	int status, args_count;
	char *cmd;
	char *args[100];

	cmd = strtok(command, " ");
	args[0] = cmd;
	args_count = 1;

	while (args_count < 99)
	{
		args[args_count] = strtok(NULL, " ");
		if (args[args_count] == NULL)
			break;
		args_count++;
	}
	args[args_count] = NULL;
	env_cmd(args);
	if (args_count > 0)
	{
		pid = check_fork();
		if (pid == 0)
		{
			search_path(args);
		}
	}
	else
		waitpid(pid, &status, 0);
}
