#include "t_int_deque.h"

bool	deque_is_empty(const t_int_deque dq)
{
	return (dq.sz == 0);
}

size_t	deque_size(const t_int_deque dq)
{
	return (dq.sz);
}
