#include "main.h"
#include <stdlib.h>

/**
* _strdup - Returns a pointer to a newly allocated space in memory,
*           which contains a copy of the string given as a parameter.
* @str: The string to duplicate.
*
* Return: Pointer to the duplicated string, or NULL if memory allocation fails.
*/
char *_strdup(char *str)
{
char *dup;
unsigned int i, len = 0;

if (str == NULL)
return (NULL);

while (str[len] != '\0') /* Calcul de la longueur de la chaîne */
len++;

dup = malloc((len + 1) * sizeof(char)); /* Allocation mémoire */
if (dup == NULL)
return (NULL);

for (i = 0; i <= len; i++) /* Copie de la chaîne */
dup[i] = str[i];

return (dup);
}

