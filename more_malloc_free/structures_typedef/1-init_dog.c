#include "dog.h"
#include <stdlib.h>

/**
* init_dog - Initializes a struct dog
* @d: Pointer to the struct dog to initialize
* @name: Name of the dog
* @age: Age of the dog
* @owner: Owner of the dog
*
* Description: If `d` is NULL, the function does nothing.
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d == NULL)
return;

d->name = name;
d->age = age;
d->owner = owner;
}

