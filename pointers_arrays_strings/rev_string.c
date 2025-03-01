#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: The string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i = 0, len = 0;
	char temp;

	/* Trouver la longueur de la chaîne */
	while (s[len] != '\0')
		len++;

	/* Échanger les caractères pour inverser la chaîne */
	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}

