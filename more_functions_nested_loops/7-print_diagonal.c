#include "main.h"

/**
 * print_diagonal - Draws a diagonal line on the terminal.
 * @n: The number of times the character '\' should be printed.
 */
void print_diagonal(int n)
{
	int i, j;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i; j++)
				_putchar(' '); /* Ajoute des espaces avant '\' */
			_putchar('\\'); /* Affiche le caractère '\' */
			_putchar('\n'); /* Nouvelle ligne */
		}
	}
	else
		_putchar('\n');
}

