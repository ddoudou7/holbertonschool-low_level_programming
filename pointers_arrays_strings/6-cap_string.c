#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The string to modify
 *
 * Return: Pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0, capitalize = 1;
	char separators[] = " \t\n,;.!?\"(){}";

	while (str[i] != '\0')
	{
		int j = 0;

		/* Vérifier si on est sur un séparateur */
		while (separators[j] != '\0')
		{
			if (str[i] == separators[j])
			{
				capitalize = 1;
				break;
			}
			j++;
		}

		/* Capitaliser si nécessaire */
		if (capitalize && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			capitalize = 0;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			capitalize = 0;
		}

		i++;
	}

	return (str);
}

