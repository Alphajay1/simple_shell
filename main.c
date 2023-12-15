#include "shell_header.h"

/**
 * main - Entry point
 *
 * Return: 0 Always
 */
int main(void)
{
	char *input_cmd = NULL;
	size_t size;

	while (1)
	{
		display_prompt();
		if (getline(&input_cmd, &size, stdin) == -1)
		{
			if (feof(stdin))
			{
				free(input_cmd);
				break;
			}
			else
			{
				perror("Input_cmd Error");
			}
			break;
		}
		input_cmd[strcspn(input_cmd, "\n")] = '\0';
		if (input_cmd[0] != '\0')
		{
			if (strcmp(input_cmd, "exit") == 0)
				exit_cmd();
			if (strchr(input_cmd, ' ') != NULL)
				exec_cmds(input_cmd);
			else
				exec_cmd(input_cmd);
		}
		free(input_cmd);
		input_cmd = NULL;
	}
	return (0);
}
