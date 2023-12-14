#include "shell_header.h"
/**
 * env_print - prints the environment
 *
 * Return: void
 */
void env_print(void)
{
	char **env_v;

	for (env_v = environ; *env_v != NULL; env_v++)
		printf("%s\n", *env_v);
}
/**
 * env_cmd - handles commands for environment
 * @args: arguments
 *
 * Return: 0 if handled, -1 on failure
 */
int env_cmd(char **args)
{
	if (args[0] != NULL && (strcmp(args[0], "env") == 0 ||
				strcmp(args[0], "printenv") == 0))
	{
		env_print();
		return (0);
	}
	return (-1);
}
