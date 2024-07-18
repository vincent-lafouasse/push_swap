#include "array_operations.h"

#include <assert.h>

bool array_contains_duplicates(const int* array, size_t len)
{
	assert(array_is_sorted(array, len));
	size_t i = 0;

	while (i < len - 1)
	{
		if (array[i] == array[i + 1])
			return true;
		i++;
	}
	return false;
}
