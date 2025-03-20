#include "3-calc.h"

/**
* op_add - Returns the sum of two numbers
* @a: First number
* @b: Second number
*
* Return: Sum of a and b
*/
int op_add(int a, int b)
{
return (a + b);
}

/**
* op_sub - Returns the difference of two numbers
* @a: First number
* @b: Second number
*
* Return: Difference of a and b
*/
int op_sub(int a, int b)
{
return (a - b);
}

/**
* op_mul - Returns the product of two numbers
* @a: First number
* @b: Second number
*
* Return: Product of a and b
*/
int op_mul(int a, int b)
{
return (a * b);
}

/**
* op_div - Returns the quotient of two numbers
* @a: First number
* @b: Second number
*
* Return: Quotient of a and b, or exits with 100 if b is 0
*/
int op_div(int a, int b)
{
if (b == 0)
{
printf("Error\n");
exit(100);
}
return (a / b);
}

/**
* op_mod - Returns the remainder of division
* @a: First number
* @b: Second number
*
* Return: Remainder of a / b, or exits with 100 if b is 0
*/
int op_mod(int a, int b)
{
if (b == 0)
{
printf("Error\n");
exit(100);
}
return (a % b);
}

