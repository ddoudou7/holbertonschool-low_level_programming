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

/* Définition de dog_t comme alias pour struct dog */
typedef struct dog dog_t;

/* Prototypes des fonctions associées */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* DOG_H */

