#include "main.h"

/**
* puts_half - Prints the second half of a string
* @str: Pointer to the string
*
* Return: void
*/
void puts_half(char *str)
{
int len = 0, start;

while (str[len] != '\0')
{
len++;
}

start = (len % 2 == 0) ? (len / 2) : ((len + 1) / 2);

while (str[start] != '\0')
{
_putchar(str[start]);
start++;
}
_putchar('\n');
}

