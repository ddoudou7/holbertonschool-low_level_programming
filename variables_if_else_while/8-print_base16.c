#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: This program prints all the numbers of base 16 in lowercase,
 * followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;
	char hex;

	/* Print digits 0-9 */
	for (num = '0'; num <= '9'; num++)
		putchar(num);

	/* Print letters a-f */
	for (hex = 'a'; hex <= 'f'; hex++)
		putchar(hex);

	putchar('\n'); /* Print new line */

	return (0);
}

