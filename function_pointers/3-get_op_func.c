#include "3-calc.h"
#include <stddef.h>
#include <string.h>

/**
 * get_op_func - Sélectionne la bonne fonction en fonction de l'opérateur
 * @s: L'opérateur passé en argument
 *
 * Return: Pointeur vers la fonction correspondant à l'opérateur
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add}, {"-", op_sub}, {"*", op_mul},
		{"/", op_div}, {"%", op_mod}, {NULL, NULL}
	};
	int i = 0;

	while (ops[i].op)
	{
		if (ops[i].op[0] == s[0] && !s[1])
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

