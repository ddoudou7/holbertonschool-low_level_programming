#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * _strdup - Creates a duplicate of a string
 * @str: The string to duplicate
 *
 * Return: Pointer to the duplicated string or NULL if failure.
 */
char *_strdup(char *str)
{
    char *dup;
    int len, i;

    if (str == NULL)
        return (NULL);

    len = strlen(str);
    dup = malloc(sizeof(char) * (len + 1));
    if (dup == NULL)
        return (NULL);

    for (i = 0; i <= len; i++)
        dup[i] = str[i];

    return (dup);
}

/**
 * new_dog - Creates a new dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the new dog_t structure, or NULL if failure.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *dog;

    dog = malloc(sizeof(dog_t));
    if (dog == NULL)
        return (NULL);

    dog->name = _strdup(name);
    if (dog->name == NULL)
    {
        free(dog);
        return (NULL);
    }

    dog->owner = _strdup(owner);
    if (dog->owner == NULL)
    {
        free(dog->name);
        free(dog);
        return (NULL);
    }

    dog->age = age;

    return (dog);
}

