#include "main.h"

/**
* _puts - Prints a string followed by a new line
* @str: Pointer to the string
*
* Return: void
*/
void _puts(char *str)
{
while (*str)
{
_putchar(*str);
str++;
}
_putchar('\n');
}

