#include "main.h"

/**
 * reverse_array - Reverses the content of an array of integers
 * @a: The array to be reversed
 * @n: The number of elements in the array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i, temp;

	for (i = 0; i < n / 2; i++)
	{
		/* Échanger a[i] et a[n-i-1] */
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}

