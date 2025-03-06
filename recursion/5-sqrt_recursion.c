#include "main.h"

/**
 * find_sqrt - Helper function to find the square root recursively
 * @n: The number to find the square root of
 * @i: The current divisor being tested
 *
 * Return: The square root, or -1 if not a perfect square
 */
int find_sqrt(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (find_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to find the square root of
 *
 * Return: The square root, or -1 if not a perfect square
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (find_sqrt(n, 0));
}

