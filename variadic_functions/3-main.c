#include "variadic_functions.h"
#include <stddef.h>  /* Ajout pour la définition de NULL */

/**
 * main - Teste la fonction print_all.
 *
 * Return: 0.
 */
int main(void)
{
    print_all("ceis", 'B', 3, "stSchool");
    print_all("cfis", 'H', 3.14159, NULL, "Holberton");
    return (0);
}

