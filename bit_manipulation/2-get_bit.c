#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index
 * @n: The number
 * @index: The index of the bit to retrieve (starting from 0)
 *
 * Return: The bit value (0 or 1), or -1 on error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	return ((n >> index) & 1);
}
