#include "shell_header.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes the string s and a trailing newline to stdout
 * @s: string to write
 *
 * Return: nothing
 */
void _puts(char *s)
{
	while (*s != '\0')
	{
		_putchar(*s);
		s++;
	}
}
