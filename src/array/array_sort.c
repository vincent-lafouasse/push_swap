#include "array_operations.h"

#include <stdbool.h>

static void ft_swap(int* a, int* b);

void sort_array(int* array, size_t len)
{
	bool is_sorted = false;
	size_t i;

	while (!is_sorted)
	{
		is_sorted = true;
		i = 0;
		while (i < len - 1)
		{
			if (array[i] > array[i + 1])
			{
				ft_swap(array + i, array + i + 1);
				is_sorted = false;
			}
			i++;
		}
	}
}

static void ft_swap(int* a, int* b)
{
	int buffer = *a;
	*a = *b;
	*b = buffer;
}
