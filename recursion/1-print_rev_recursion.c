#include "main.h"

/**
 * _print_rev_recursion - Prints a string in reverse using recursion
 * @s: The string to be printed
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0') /* Condition d'arrêt */
		return;

	_print_rev_recursion(s + 1); /* Appel récursif avant d'afficher */
	_putchar(*s);
}

