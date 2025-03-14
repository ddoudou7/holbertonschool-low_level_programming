#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees memory allocated for a dog
 * @d: Pointer to the dog to be freed
 */
void free_dog(dog_t *d)
{
    if (d != NULL)  /* Vérifie que d n'est pas NULL */
    {
        if (d->name != NULL)  /* Vérifie que name n'est pas NULL avant de le libérer */
            free(d->name);
        if (d->owner != NULL)  /* Vérifie que owner n'est pas NULL avant de le libérer */
            free(d->owner);
        free(d);  /* Libère la structure elle-même */
    }
}

