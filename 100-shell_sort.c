#include "sort.h"
/**
 * shell_sort -Sort an array using shell_sort algorithm
 * @array: The array
 * @size: The size of the array
 * Return: NULL
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, a, b;
	int temp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (a = gap; a < size; a++)
		{
			temp = array[a];
			b = a;
			while (b >= gap && array[b - gap] > temp)
			{
				array[b] = array[b - gap];
				b -= gap;
			}
			array[b] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
