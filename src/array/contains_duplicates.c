#include "array_operations.h"

#include <assert.h>

bool array_contains_duplicates(const int* sorted_array, size_t len)
{
	assert(array_is_sorted(sorted_array, len));
	size_t i = 0;

	while (i < len - 1)
	{
		if (sorted_array[i] == sorted_array[i + 1])
			return true;
		i++;
	}
	return false;
}
