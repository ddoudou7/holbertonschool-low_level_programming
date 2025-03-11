# malloc_free

Ce projet concerne l'allocation dynamique en C avec `malloc` et `free`.

## 📌 Objectifs :
- Comprendre la différence entre **allocation automatique et dynamique**.
- Savoir **utiliser `malloc` et `free`** correctement.
- Éviter les **fuites mémoire avec `valgrind`**.
- Respecter les **règles strictes du projet** (Betty, pas de `printf`, pas de `calloc`, etc.).

## 📂 Fichiers :
- `0-create_array.c` : Fonction qui crée un tableau de caractères et l'initialise avec un caractère donné.
- `main.h` : Contient les prototypes des fonctions du projet.

## 🚀 Compilation :
Toutes les fonctions sont compilées avec :
```sh
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 fichier.c -o fichier

