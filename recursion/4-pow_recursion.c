#include "main.h"

/**
 * _pow_recursion - Returns the value of x raised to the power of y
 * @x: The base number
 * @y: The exponent
 *
 * Return: x^y, or -1 if y is negative
 */
int _pow_recursion(int x, int y)
{
	if (y < 0) /* Si l'exposant est négatif, retourne -1 */
		return (-1);
	if (y == 0) /* x^0 = 1 */
		return (1);
	return (x * _pow_recursion(x, y - 1)); /* Récursion */
}

