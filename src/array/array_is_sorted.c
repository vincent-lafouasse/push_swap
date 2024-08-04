#include "array_operations.h"

bool array_is_sorted(const t_i32* array, size_t len)
{
	size_t i = 0;

	while (i < len - 1)
	{
		if (array[i] > array[i + 1])
			return false;
		i++;
	}
	return true;
}
