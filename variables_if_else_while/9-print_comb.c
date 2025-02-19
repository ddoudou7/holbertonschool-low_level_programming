#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: This program prints all possible combinations
 * of single-digit numbers, separated by ", ", in ascending order.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;

	for (num = 0; num <= 9; num++)
	{
		putchar(num + '0'); /* Convert int to char */

		/* Print ", " except after the last digit */
		if (num != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n'); /* Print new line */

	return (0);
}

