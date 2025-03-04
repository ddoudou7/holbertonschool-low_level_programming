#include "main.h"

/**
 * _strstr - Locates a substring
 * @haystack: The main string to search in
 * @needle: The substring to find
 *
 * Return: Pointer to the beginning of located substring, or NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (!*needle)
		return (haystack);

	for (i = 0; haystack[i]; i++)
	{
		for (j = 0; needle[j] && haystack[i + j] == needle[j]; j++)
			;

		if (!needle[j])
			return (haystack + i);
	}

	return (0);
}

