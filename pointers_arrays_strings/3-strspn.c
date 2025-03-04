#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: The main string to check
 * @accept: The characters to match
 *
 * Return: Number of bytes in the initial segment of s
 * consisting only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, count = 0;

	for (i = 0; s[i]; i++)
	{
		int found = 0;

		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}

		if (!found)
			break;
		count++;
	}

	return (count);
}

