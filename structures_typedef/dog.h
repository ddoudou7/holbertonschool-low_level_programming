#ifndef DOG_H
#define DOG_H

/**
* struct dog - Structure représentant un chien
* @name: Nom du chien (chaîne de caractères)
* @age: Âge du chien (nombre flottant)
* @owner: Propriétaire du chien (chaîne de caractères)
*
* Description: Structure pour stocker des informations sur un chien.
*/
struct dog
{
char *name;
float age;
char *owner;
};

/* Prototypes des fonctions associées */
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_H */

