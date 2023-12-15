#include "shell_header.h"

/**
 * display_prompt - displays a prompt to the screen
 *
 * Return: screen prompt
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_puts("$ ");
		fflush(stdout);
	}
	else
	{
	}
}
