#include "sort.h"

/**
 * selection_sort - Trie un tableau d'entiers par sélection
 * @array: Pointeur vers le tableau à trier
 * @size: Nombre d'éléments dans le tableau
 *
 * Return: None
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min_id;
	int temp;

	if (array == NULL || size == 0)
		return;
	
	for (i = 0; i < size; i++)
	{
		min_id = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_id])
				min_id = j;
		}

		temp = array[min_id];
		array[min_id] = array[i];
		array[i] = temp;

		print_array(array, size);
	}
}
