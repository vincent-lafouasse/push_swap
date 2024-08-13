#include "array_operations.h"
#include <assert.h>

bool	sorted_array_contains_duplicates(const t_i32 *sorted_array, size_t len)
{
	size_t	i;

	assert(array_is_sorted(sorted_array, len));
	i = 0;
	while (i < len - 1)
	{
		if (sorted_array[i] == sorted_array[i + 1])
			return (true);
		i++;
	}
	return (false);
}
