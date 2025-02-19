#include "main.h"

/**
 * main - Entry point
 *
 * Description: This program prints "_putchar",
 * followed by a new line, using the _putchar function.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char text[] = "_putchar";
	int i;

	for (i = 0; text[i] != '\0'; i++)
		_putchar(text[i]);

	_putchar('\n'); /* Print new line */

	return (0);
}

