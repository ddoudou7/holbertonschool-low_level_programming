#include "main.h"

/**
 * print_alphabet_x10 - Prints the alphabet in lowercase 10 times,
 * followed by a new line.
 */
void print_alphabet_x10(void)
{
	int i = 0;
	char ch;

	while (i < 10)
	{
		ch = 'a';
		while (ch <= 'z')
		{
			_putchar(ch);
			ch++;
		}
		_putchar('\n');
		i++;
	}
}

