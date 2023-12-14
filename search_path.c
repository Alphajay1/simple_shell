#include "shell_header.h"
/**
 * search_path - searchs for a command in a path
 * @args: arguments passed
 *
 * Return: nothing
 */
void search_path(char *args[])
{
	char *path, *token;
	char path_line[1024];
	int is_command;
	char delim = '/';

	path = getenv("PATH");
	is_command = 0;

	if (strchr(args[0], '/') != NULL)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
	}
	token = strtok(path, ":");
	while(token != NULL)
	{
		snprintf(path_line, sizeof(path_line), "%s%c%s", token, delim, args[0]);
		if (access(path_line, X_OK) == 0)
		{
			is_command = 1;
			break;
		}
		token = strtok(NULL, ":");
	}
	if (!is_command)
	{
		printf("command not found %s\n", args[0]);
		exit(EXIT_FAILURE);
	}
	if (execve(path_line, args, NULL) == -1)
	{
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}
