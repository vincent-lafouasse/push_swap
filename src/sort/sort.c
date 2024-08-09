#include "sort_internals.h"

t_int_deque sort(t_stacks* stacks)
{
	return radix_sort(stacks);
}
