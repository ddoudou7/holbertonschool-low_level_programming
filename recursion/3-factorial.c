#include "main.h"

/**
 * factorial - Returns the factorial of a given number using recursion
 * @n: The number to calculate the factorial of
 *
 * Return: Factorial of n, or -1 if n is negative
 */
int factorial(int n)
{
	if (n < 0) /* Gestion des erreurs */
		return (-1);
	if (n == 0) /* Factorielle de 0 = 1 */
		return (1);
	return (n * factorial(n - 1)); /* Appel récursif */
}

