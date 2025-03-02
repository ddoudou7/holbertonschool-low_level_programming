#include "main.h"

/**
 * is_separator - Checks if a character is a separator
 * @c: The character to check
 *
 * Description: This function checks if the given character `c`
 * is one of the predefined word separators: space, tab, newline,
 * comma, semicolon, period, exclamation mark, question mark,
 * double quote, parenthesis, or curly braces.
 *
 * Return: 1 if the character is a separator, 0 otherwise.
 */
int is_separator(char c)
{
	char separators[] = " \t\n,;.!?\"(){}";
	int j;

	for (j = 0; separators[j] != '\0'; j++)
	{
		if (c == separators[j])
			return (1);
	}
	return (0);
}

/**
 * cap_string - Capitalizes all words of a string
 * @str: The string to modify
 *
 * Description: This function takes a string and capitalizes
 * the first letter of each word. A word is defined as any
 * sequence of characters separated by the predefined word
 * separators (spaces, punctuation marks, etc.).
 *
 * Return: Pointer to the modified string.
 */
char *cap_string(char *str)
{
	int i = 0;
	int capitalize_next = 1;

	while (str[i])
	{
		if (capitalize_next && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;

		capitalize_next = is_separator(str[i]);
		i++;
	}

	return (str);
}

