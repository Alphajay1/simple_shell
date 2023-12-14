#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void display_prompt(void);
void input_command(char cmd[], char *par[]);

/**
 * main - Entry point of the program
 *
 * Retrun: 0 on success.
 */
int main(void)
{
	char cmd[100];
	char command[100];
	char *parameters[20];
	char *envp[] = {(char *) "PATH=/bin", 0};
	pid_t pid;

	while (1)
	{
		display_prompt();
		input_command(command, parameters);
		pid = fork();
		if (pid == -1)
		{
			perror("Fork Failed\n");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			strcpy(cmd, "/bin/");
			strcat(cmd, command);
			execve(cmd, parameters, envp);
		}
		else
		{
			wait(NULL);
			printf("Done with execve\n");
		}
		if (strcmp(command, "exit") == 0)
			break;
	}
	return (0);
}
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}
	else
	{
	}
}
void input_command(char cmd[], char *par[])
{
	char *input = NULL;
	size_t size = 0;
	ssize_t read_line;
	int i = 0, j = 0;
	char *argv[100];
	char *token = NULL;
	char *delim = " ";
	size_t len = 0;

	read_line = getline(&input, &size, stdin);
	if (read_line == -1)
	{
		if (feof(stdin))
		{
			printf("\nEOF\n");
			free(input);
			exit(EXIT_FAILURE);
		}
		else
		{
			perror("Input Error");
			exit(EXIT_FAILURE);
		}
	}
	len = strlen(input);
	if (len > 0 && input[len - 1] == '\n')
		input[len - 1] = '\0';
	token = strtok(input, delim);
	while (token != NULL)
	{
		argv[i++] = strdup(token);
		token = strtok(NULL, delim);
	}
	strcpy(cmd, argv[0]);
	for (j = 0; j < i; j++)
		par[j] = argv[j];
	par[i] = NULL;
}
