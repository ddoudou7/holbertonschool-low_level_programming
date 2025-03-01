#include "main.h"

/**
 * _strncat - Concatenates two strings with at most `n` bytes from `src`
 * @dest: Destination string (must have enough space)
 * @src: Source string to append
 * @n: Maximum number of bytes to append from `src`
 *
 * Return: Pointer to the resulting string `dest`
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	/* Trouver la fin de `dest` */
	while (dest[i] != '\0')
		i++;

	/* Ajouter au plus `n` caractères de `src` */
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Ajouter le null byte final */
	dest[i] = '\0';

	return (dest);
}

