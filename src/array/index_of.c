#include "array_operations.h"

int index_of(int value, const int* array, size_t len)
{
	int i = 0;

	while (i < (int)len)
	{
		if (array[i] == value)
			return i;
		i++;
	}
	return -1;
}
