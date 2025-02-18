#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: This program prints all single-digit numbers
 * of base 10 starting from 0, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
		printf("%d", num);

	printf("\n"); /* Print new line */

	return (0);
}

