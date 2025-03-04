#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: The string to search
 * @accept: The set of bytes to search for
 *
 * Return: Pointer to the first matching byte in s, or NULL if not found
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
				return (s);
		}
		s++;
	}

	return (0);
}

