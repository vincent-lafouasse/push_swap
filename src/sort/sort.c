#include "sort_internals.h"

t_int_deque sort(t_stacks* stacks)
{
	if (!stacks || stacks->a.sz <= 1)
		return deque_new();
	return radix_sort(stacks);
}
