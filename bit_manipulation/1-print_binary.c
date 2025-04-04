#include "main.h"
#include <unistd.h>

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to print in binary
 */
void print_binary(unsigned long int n)
{
	int started = 0;
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);

	while (mask)
	{
		if (n & mask)
		{
			started = 1;
			write(1, "1", 1);
		}
		else if (started)
		{
			write(1, "0", 1);
		}
		mask >>= 1;
	}

	if (!started)
		write(1, "0", 1);
}
