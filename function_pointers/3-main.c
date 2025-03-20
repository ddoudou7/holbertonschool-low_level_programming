#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* check_operator - Vérifie si l'opérateur est valide
* @op: L'opérateur en argument
*
* Return: 1 si valide, 0 sinon
*/
int check_operator(char *op)
{
char *valid_ops[] = {"+", "-", "*", "/", "%", NULL};
int i;

for (i = 0; valid_ops[i] != NULL; i++)
{
if (strcmp(op, valid_ops[i]) == 0)
return (1);
}
return (0);
}

/**
* main - Entry point
* @argc: Argument count
* @argv: Argument vector
*
* Return: 0 on success, exits with error codes on failure
*/
int main(int argc, char *argv[])
{
int num1, num2, result;
int (*operation)(int, int);

if (argc != 4)
{
printf("Error\n");
exit(98);
}

if (strlen(argv[2]) != 1 || !check_operator(argv[2]))
{
printf("Error\n");
exit(99);
}

num1 = atoi(argv[1]);
num2 = atoi(argv[3]);

if ((*argv[2] == '/' || *argv[2] == '%') && num2 == 0)
{
printf("Error\n");
exit(100);
}

operation = get_op_func(argv[2]);
result = operation(num1, num2);
printf("%d\n", result);

return (0);
}

