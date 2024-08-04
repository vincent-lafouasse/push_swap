#include "array_operations.h"

#include <stdbool.h>

static void ft_swap(int32_t* a, int32_t* b);

void sort_array(int32_t* array, size_t len)
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

static void ft_swap(int32_t* a, int32_t* b)
{
	int32_t buffer = *a;
	*a = *b;
	*b = buffer;
}
