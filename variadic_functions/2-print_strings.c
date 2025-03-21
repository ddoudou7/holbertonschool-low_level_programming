#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
* print_strings - Imprime des chaînes de caractères suivies
*                 d'une nouvelle ligne.
* @separator: Chaîne à afficher entre les chaînes.
* @n: Nombre de chaînes passées en argument.
*/
void print_strings(const char *separator, const unsigned int n, ...)
{
va_list args;
unsigned int i;
char *str;

va_start(args, n);

for (i = 0; i < n; i++)
{
str = va_arg(args, char *);
if (str == NULL)
printf("(nil)");
else
printf("%s", str);

if (separator != NULL && i < n - 1)
printf("%s", separator);
}

printf("\n");
va_end(args);
}

