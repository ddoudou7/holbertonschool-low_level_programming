#include <stdlib.h>
#include "dog.h"

/**
 * _strdup - Creates a duplicate of a string without using strlen
 * @str: The string to duplicate
 *
 * Return: Pointer to the duplicated string or NULL if failure.
 */
char *_strdup(char *str)
{
	char *dup;
	int i = 0;

	if (str == NULL)
		return (NULL);

	/* Calculer la longueur de la chaîne */
	while (str[i] != '\0')
		i++;

	/* Allouer de la mémoire pour la copie */
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);

	/* Copier la chaîne */
	for (i = 0; str[i] != '\0'; i++)
		dup[i] = str[i];
	dup[i] = '\0';

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

