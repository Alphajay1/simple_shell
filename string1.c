#include "shell_header.h"

/**
 * _strcspn - gets the length of a prefix substring
 * @s: initial string segment
 * @reject: string reject
 *
 * Return: number of bytes in the initial segment of s,
 * which are not in the string reject
 */
size_t _strcspn(const char *s, const char *reject)
{
	size_t count = 0;
	const char *index = reject;

	while (*s != '\0')
	{
		while (*index != '\0')
		{
			if (*s == *index)
				return (count);
			index++;
		}
		s++;
		count++;
		index = reject;
	}
	return (count);
}
