#include "main.h"
#include <stdlib.h>

/**
* alloc_grid - Allocates a 2D array of integers and initializes elements to 0.
* @width: Number of columns.
* @height: Number of rows.
*
* Return: Pointer to the allocated 2D array, or NULL on failure.
*/
int **alloc_grid(int width, int height)
{
int **grid;
int i, j;

if (width <= 0 || height <= 0)
return (NULL);

/* Allocation du tableau de pointeurs */
grid = malloc(height * sizeof(int *));
if (grid == NULL)
return (NULL);

/* Allocation de chaque ligne */
for (i = 0; i < height; i++)
{
grid[i] = malloc(width * sizeof(int));
if (grid[i] == NULL)
{
/* Libérer les lignes déjà allouées en cas d'échec */
while (i > 0)
free(grid[--i]);
free(grid);
return (NULL);
}
/* Initialiser à 0 */
for (j = 0; j < width; j++)
grid[i][j] = 0;
}

return (grid);
}

