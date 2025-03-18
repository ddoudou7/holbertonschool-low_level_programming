#include "function_pointers.h"
#include <stddef.h>

/**
 * print_name - Prints a name using a given function
 * @name: The name to print
 * @f: A pointer to the function that prints the name
 *
 * Description: This function takes a name and a function pointer,
 * and calls the function to print the name.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}

