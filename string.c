#include "shell_header.h"

/**
 * _strlen - calculates string length
 * @str: string to be calculated.
 *
 * Return: length of the string.
 */

size_t _strlen(const char *str)
{
	size_t i = 0;

	if (!str)
		return (0);
	while (*str++)
		i++;

	return (i);
}

/**
 * _strcpy - copies a string
 * @src: source string
 * @dest: destination string
 *
 * Return: dest string
 */
char *_strcpy(char *dest, const char *src)
{
	size_t index = 0;

	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

/**
 * _strcat - appends the src string to the end of the dest string
 * @src: source string
 * @dest: destination string
 *
 * Return: dest string
 */
char *_strcat(char *dest, const char *src)
{
	char *dest_original = dest;

	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_original);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if same, -1 if s1 is smaller, 1 if s1 is larger
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 != '\0')
		return (-1);
	if (*s1 != '\0' && *s2 == '\0')
		return (1);
	return (0);
}
