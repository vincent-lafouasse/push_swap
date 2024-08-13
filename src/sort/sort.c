#include "sort_internals.h"

t_error sort(t_stacks* stacks, t_int_deque* ops_out)
{
	if (!stacks || !ops_out)
		return ERROR_NULL_OUT_PARAM;
	if (stacks->a.sz <= 1)
	{
		deque_clear(ops_out);
		*ops_out = deque_new();
		return NO_ERROR;
	}
	return radix_sort(stacks, ops_out);
}
