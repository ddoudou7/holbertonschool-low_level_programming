#include "main.h"

/**
 * print_rev - Prints a string in reverse
 * @s: The string to print
 *
 * Return: void
 */
void print_rev(char *s)
{
	int length = 0;

	/* Trouver la longueur de la chaîne */
	while (s[length] != '\0')
		length++;

	/* Afficher les caractères en sens inverse */
	while (length--)
		_putchar(s[length]);

	_putchar('\n');
}

