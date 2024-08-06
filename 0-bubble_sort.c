#include "sort.h"

/**
 * bubble_sort - Trie un tableau d'entiers
 * @array: Pointeur vers le tableau à trier
 * @size: Nombre d'éléments dans le tableau
 *
 * Description: Utilise l'algorithme de tri à bulle pour trier le tableau.
 *             Affiche le tableau après chaque échange d'éléments.
 *
 * Return: None
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;
	int swapped;

	for (i = 0; i < size; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;

				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
