#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The string to capitalize
 *
 * Return: Pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0;
	int capitalize = 1; /* Flag pour savoir si on doit capitaliser */

	char separators[] = " \t\n,;.!?\"(){}";

	while (str[i] != '\0')
	{
		int j = 0;

		/* Vérifier si on est sur un séparateur */
		while (separators[j] != '\0')
		{
			if (str[i] == separators[j])
				capitalize = 1;
			j++;
		}

		/* Si on est sur une lettre et qu'on doit capitaliser */
		if (capitalize && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 32; /* Convertir en majuscule */
			capitalize = 0;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			capitalize = 0; /* Si c'est déjà une majuscule, on continue */
		}

		i++;
	}

	return (str);
}

