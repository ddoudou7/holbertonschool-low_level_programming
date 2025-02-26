#include <stdio.h>
#include "main.h"

/**
* main - Tests the reset_to_98 function
*
* Return: Always 0.
*/
int main(void)
{
int n;

n = 402;
printf("Before: n = %d\n", n);
reset_to_98(&n);
printf("After: n = %d\n", n);

return (0);
}

