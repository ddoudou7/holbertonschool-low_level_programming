#include "main.h"

/**
 * _strncpy - Copies a string up to `n` bytes
 * @dest: Destination buffer
 * @src: Source string
 * @n: Number of bytes to copy
 *
 * Return: Pointer to the resulting string `dest`
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	/* Copier les caractères de src vers dest */
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	/* Compléter avec des `\0` si src est plus courte que `n` */
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}

