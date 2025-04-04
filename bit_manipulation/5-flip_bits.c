#include "main.h"

/**
 * flip_bits - Counts the number of bits to flip to get from n to m
 * @n: First number
 * @m: Second number
 *
 * Return: Number of bits that differ
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int count = 0;

	while (xor)
	{
		if (xor & 1)
			count++;
		xor >>= 1;
	}

	return (count);
}
