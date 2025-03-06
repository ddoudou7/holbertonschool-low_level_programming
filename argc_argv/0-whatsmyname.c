#include <stdio.h>

/**
 * main - Prints the program name followed by a new line
 * @argc: Number of command line arguments (unused)
 * @argv: Array containing command line arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}

