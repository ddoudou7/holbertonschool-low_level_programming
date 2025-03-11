#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings into a newly allocated memory space.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Pointer to the newly allocated concatenated string,
 *         or NULL if memory allocation fails.
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int i, j, len1 = 0, len2 = 0;

	/* Traiter NULL comme une chaîne vide */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculer la longueur des chaînes */
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	/* Allocation mémoire pour la concaténation + 1 pour '\0' */
	concat = malloc((len1 + len2 + 1) * sizeof(char));
	if (concat == NULL)
		return (NULL);

	/* Copier s1 */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* Copier s2 */
	for (j = 0; j < len2; j++, i++)
		concat[i] = s2[j];

	concat[i] = '\0'; /* Null-terminate */
	return (concat);
}

