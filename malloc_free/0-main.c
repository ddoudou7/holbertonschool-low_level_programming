#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* main - check the code
*
* Return: Always 0.
*/
int main(void)
{
char *buffer;
int i;  /* Déclaration de i AVANT la boucle */

buffer = create_array(10, 'H');
if (buffer == NULL)
{
printf("Failed to allocate memory\n");
return (1);
}

for (i = 0; i < 10; i++)  /* Correction ici */
printf("%c ", buffer[i]);

printf("\n");
free(buffer);
return (0);
}

