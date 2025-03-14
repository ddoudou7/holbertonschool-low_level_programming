#include <stdio.h>
#include "dog.h"

/**
* print_dog - Prints a struct dog
* @d: Pointer to the struct dog to print
*
* Description: If `d` is NULL, the function prints nothing.
* If any element of `d` is NULL, it prints `(nil)` instead.
*/
void print_dog(struct dog *d)
{
if (d == NULL)
return;

printf("Name: %s\n", (d->name) ? d->name : "(nil)");
printf("Age: %f\n", d->age);
printf("Owner: %s\n", (d->owner) ? d->owner : "(nil)");
}

