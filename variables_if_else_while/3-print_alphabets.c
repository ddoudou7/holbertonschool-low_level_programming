#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: This program prints the alphabet in lowercase,
 * then in uppercase, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char lower[] = "abcdefghijklmnopqrstuvwxyz";
	char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	/* Print lowercase and uppercase using putchar */
	int i;

	for (i = 0; lower[i] != '\0'; i++)
		putchar(lower[i]);
	for (i = 0; upper[i] != '\0'; i++)
		putchar(upper[i]);
	putchar('\n'); /* Print new line */

	return (0);
}

